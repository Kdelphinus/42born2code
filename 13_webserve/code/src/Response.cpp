#include "../includes/Response.hpp"

Response::Response() : _result(NULL), _resultSize(0), _sendCnt(0) {
  _statusCodes[200] = " OK";
  _statusCodes[201] = " Created";
  _statusCodes[202] = " Accepted";
  _statusCodes[204] = " No Content";
  _statusCodes[300] = " Multiple Choice";
  _statusCodes[301] = " Moved Permanently";
  _statusCodes[303] = " See Other";
  _statusCodes[304] = " Not Modified";
  _statusCodes[307] = " Temporary Redirect";
  _statusCodes[400] = " Bad Request";
  _statusCodes[401] = " Unauthorized";
  _statusCodes[403] = " Forbidden";
  _statusCodes[404] = " Not Found";
  _statusCodes[405] = " Method Not Allowed";
  _statusCodes[406] = " Not Acceptable";
  _statusCodes[408] = " Request Timeout";
  _statusCodes[409] = " Conflict";
  _statusCodes[410] = " Gone";
  _statusCodes[412] = " Precondition Failed";
  _statusCodes[413] = " Request Entity Too Large";
  _statusCodes[414] = " URI Too Long";
  _statusCodes[415] = " Unsupported Media Type";
  _statusCodes[500] = " Server Error";
}

Response::~Response() {
  if (_result != NULL) delete[] _result;
}

void Response::convertCGI(const std::string &cgiResult) {
  size_t bodystart = cgiResult.find("\r\n\r\n");
  if (bodystart == std::string::npos) {
    std::cerr << "CGI result error" << std::endl;
    setStatusLine(500);
  } else {
    bodystart += 4;
  }

  std::stringstream headerStream(cgiResult.substr(0, bodystart));
  std::string line;

  _headers.clear();
  _statusLine.clear();
  while (std::getline(headerStream, line, '\r') && line != "\n") {
    if (line.find("HTTP/1.1") != std::string::npos) {
      _statusLine += line;
    } else {
      size_t pos = line.find(":");
      if (pos == line.npos) break;
      size_t valueStartPos = line.find_first_not_of(" ", pos + 1);
      size_t keyStartPos = line.find_first_not_of("\n", 0);
      _headers[line.substr(keyStartPos, pos - keyStartPos)] =
          line.substr(valueStartPos);
    }
  }
  _body = cgiResult.substr(bodystart);

  if (_statusLine == "") {
    if (_headers.find("Status") != _headers.end()) {
      _statusLine += "HTTP/1.1 ";
      _statusLine += _headers["Status"];
      _headers.erase("Status");
    } else {
      setStatusLine(200);
    }
  }
  if (_headers.find("Content-Length") == _headers.end()) {
    setHeaders("Content-Length", ftItos(_body.size()));
  }
  setResult();
}

void Response::directoryListing(std::string path) {
  DIR *dir;
  struct dirent *ent;

  if ((dir = opendir(path.c_str())) != NULL) {
    /* print all the files and directories within directory */
    while ((ent = readdir(dir)) != NULL) {
      _body += "<a href=\"";
      _body += ent->d_name;
      if (ent->d_type == DT_DIR)
        _body += "/\">";
      else if (std::string(&ent->d_name[ent->d_namlen - 5]) != ".html")
        _body += "\" download>";
      else
        _body += "\">";
      _body += ent->d_name;
      _body += "</a><br>";
    }
    closedir(dir);
  } else {
    std::cout << "directory error : " << path.c_str() << std::endl;
    /* could not open directory */
    return;
  }
  _headers["Content-Type"] = "text/html";
  _headers["Content-Length"] = ftItos(_body.size());
  setStatusLine(200);
  setResult();
}

int Response::sendResponse(int clientSocket) {
  size_t chunk = 32768;

  if (_resultSize < chunk + _sendCnt) chunk = _resultSize - _sendCnt;
  ssize_t bytesWritten = write(clientSocket, _result + _sendCnt, chunk);
  if (bytesWritten == -1) {
    std::cerr << "client write error!" << std::endl;
    return EXIT_FAILURE;
  }
  _sendCnt += bytesWritten;

  return EXIT_SUCCESS;
}

const std::string &Response::getBody() const { return _body; }

void Response::setRedirectRes(int statusCode) {
  std::string location = _headers["Location"];
  _statusLine.clear();
  _headers.clear();
  _body.clear();

  _statusLine += "HTTP/1.1 ";
  _statusLine += ftItos(statusCode).c_str();
  _statusLine += _statusCodes[statusCode];
  _headers["Content-Type"] = "text/html";
  _headers["Location"] = location;
  _body += "<html>\n<head><title>";
  _body += ftItos(statusCode);
  _body += _statusCodes[statusCode];
  _body += "</title></head>\n<body>\n<center><h1>";
  _body += ftItos(statusCode);
  _body += _statusCodes[statusCode];
  _body +=
      "</h1></center>\n<hr><center>webserver/1.0.0</center>\n</body>\n</"
      "html>";
  _headers["Content-Length"] = ftItos(_body.size());
  setResult();
}

void Response::setErrorRes(int statusCode) {
  std::ifstream tmp;
  std::stringstream ss;

  _statusLine.clear();
  _headers.clear();
  _body.clear();

  _statusLine += "HTTP/1.1 ";
  _statusLine += ftItos(statusCode);
  _statusLine += _statusCodes[statusCode];
  _headers["Content-Type"] = "text/html";
  if (tmp.is_open() == false) {
    std::cout << "handle error 500" << std::endl;
    _headers["Content-Type"] = "text/plain";
    statusCode = 500;
  }
  if (statusCode == 404) {
    tmp.open("./error404.html");
  } else if (statusCode == 405) {
    tmp.open("./error405.html");
  } else if (statusCode == 408) {
    tmp.open("./error408.html");
  } else if (statusCode == 413) {
    tmp.open("./error413.html");
  } else if (statusCode == 414) {
    tmp.open("./error414.html");
  } else if (statusCode == 500) {
    tmp.open("./error500.html");
  } else {
    tmp.open("./error.html");
  }
  if (tmp.is_open()) {
    ss << tmp.rdbuf();
    setBody(ss);
  } else {
    _body += _statusCodes[statusCode];
    _body += ": Error";
  }
  if (statusCode == 408) {
    _headers["Connection"] = "close";
  }
  _headers["Content-Length"] = ftItos(_body.size());
  setResult();
}

bool Response::isInHeader(const std::string &key) {
  if (_headers.find(key) == _headers.end()) return false;
  return true;
}

void Response::setResult() {
  _headers["Date"] = getCurrentTime();
  std::string resultHeader;

  resultHeader += _statusLine;
  resultHeader += "\r\n";

  std::map<std::string, std::string>::iterator it;
  for (it = _headers.begin(); _headers.end() != it; it++) {
    resultHeader += it->first;
    resultHeader += ": ";
    resultHeader += it->second;
    resultHeader += "\r\n";
  }
  resultHeader += "\r\n";

  _resultSize = resultHeader.size() + _body.size();
  _result = new char[_resultSize + 1];
  memcpy(_result, resultHeader.c_str(), resultHeader.size());
  memcpy(_result + resultHeader.size(), _body.c_str(), _body.size());
  _result[_resultSize] = '\0';
}

void Response::setStatusLine(int code) {
  _statusLine += "HTTP/1.1 ";
  _statusLine += ftItos(code);
  _statusLine += _statusCodes[code];
}

void Response::setHeaders(const std::string &key, const std::string &value) {
  _headers[key] = value;
}

void Response::setBody(std::stringstream &buffer) { _body = buffer.str(); }

bool Response::isFullWrite() const {
  if (_sendCnt == _resultSize) return true;
  return false;
}