#include "../includes/Request.hpp"

Request::Request()
    : _mime("text/html"),
      _status(200),
      _isFullHeader(false),
      _isChunked(false),
      _chunkedSize(0),
      _isFullReq(false),
      _locList(NULL),
      _locBlock(NULL) {
  _mimeTypes["html"] = "text/html";
  _mimeTypes["css"] = "text/css";
  _mimeTypes["js"] = "text/javascript";
  _mimeTypes["jpg"] = "image/jpeg";
  _mimeTypes["png"] = "image/png";
  _mimeTypes["gif"] = "image/gif";
  _mimeTypes["txt"] = "text/plain";
  _mimeTypes["pdf"] = "application/pdf";
  _mimeTypes["json"] = "application/json";
  _mimeTypes["ttf"] = "font/ttf";
  _mimeTypes["woff"] = "font/woff";
  _mimeTypes["woff2"] = "font/woff2";
  _mimeTypes["otf"] = "font/otf";
  _mimeTypes["else"] = "application/octet-stream";
  _mimeTypes["directory"] = "directory";
}

Request::~Request() {}

void Request::parseUrl() {
  std::string uri = _header["URI"];
  size_t pos = uri.find("://");

  if (pos == uri.npos)
    pos = 0;
  else
    pos += 3;
  pos = uri.find('/', pos);
  if (pos == uri.npos) pos = 0;
  try {
    _header["RawURI"] = uri.substr(pos, uri.find('?', pos) - pos);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    std::cerr << "substr error" << std::endl;
  }
}

void Request::setHeader() {
  std::stringstream header(_rawContents);
  std::string line;
  if (_rawContents.find("\r\n\r\n") + 3 >= 8192) {
    _status = 414;
    _isFullReq = true;
    return;
  }
  std::getline(header, line, '\r');
  std::stringstream lineStream(line);
  lineStream >> _header["Method"] >> _header["URI"] >> _header["protocol"];
  parseUrl();

  while (std::getline(header, line, '\r') && line != "\n") {
    size_t pos = line.find(":");
    if (pos == line.npos) {
      _status = 400;
    }
    size_t valueStartPos = line.find_first_not_of(" ", pos + 1);
    size_t keyStartPos = line.find_first_not_of("\n", 0);

    _header[line.substr(keyStartPos, pos - keyStartPos)] =
        line.substr(valueStartPos);
  }
  if (_header.find("Transfer-Encoding") != _header.end()) {
    _isChunked = true;
  }
  if (_header.find("Host") == _header.end()) {
    _status = 400;
  } else if (_header["Method"] != "GET" && _header["Method"] != "POST" &&
             _header["Method"] != "DELETE" && _header["Method"] != "PUT") {
    _status = 405;
  } else {
    _host = _header["Host"];
  }
  _isFullHeader = true;
}

void Request::parsing(SPSBList *serverBlockList, LocationMap &locationMap) {
  if (_isFullHeader == false &&
      _rawContents.find("\r\n\r\n") == std::string::npos)
    return;
  else if (_isFullHeader == false) {
    setHeader();
    _rawContents.erase(0, _rawContents.find("\r\n\r\n") + 4);
    setLocBlock(serverBlockList, locationMap);
    setMime();
  } else if (_header.find("Content-Length") != _header.end() &&
             static_cast<int>(_rawContents.size()) !=
                 ftStoi(_header["Content-Length"]))
    return;
  else if (_isChunked == true && _rawContents.size() < _chunkedSize)
    return;

  if (_isFullHeader == true && _isFullReq == false) {
    if (_isChunked) {
      if (_chunkedSize == 0) {
        if (_rawContents.find("\r\n") == std::string::npos) return;
        _chunkedSize =
            hexToDecimal(_rawContents.substr(0, _rawContents.find("\r\n"))) + 2;
        _rawContents.erase(0, _rawContents.find("\r\n") + 2);
      }
      while (_rawContents.size() >= _chunkedSize) {
        _body.append(_rawContents.c_str(), _chunkedSize - 2);  // CRLF 제외
        _rawContents.erase(0, _chunkedSize);
        if (_chunkedSize == 2) {
          _isFullReq = true;
          _header.erase("Transfer-Encoding");
          break;
        } else if (_rawContents.find("\r\n") != std::string::npos) {
          _chunkedSize =
              hexToDecimal(_rawContents.substr(0, _rawContents.find("\r\n"))) +
              2;
          _rawContents.erase(0, _rawContents.find("\r\n") + 2);
        } else {
          _chunkedSize = 0;
          break;
        }
      }
      if (_body.size() > _locBlock->getClientMaxBodySize()) {
        _status = 413;
        _isFullReq = true;
      }
    } else {
      size_t conLen = ftStoi(_header["Content-Length"]);
      if (conLen > _locBlock->getClientMaxBodySize()) {
        _status = 413;
        _isFullReq = true;
      }
      _body += _rawContents;
      if (_body.size() == conLen) _isFullReq = true;
      _rawContents.clear();
    }
  }
}

// 같은 포트를 공유하는 가상 호스트 리스트
void Request::setLocBlock(SPSBList *serverBlockList, LocationMap &locationMap) {
  std::string requestURI = getHeaderByKey("RawURI");
  ServerBlock *sb = NULL;

  for (SPSBList::iterator it = serverBlockList->begin();
       it != serverBlockList->end(); it++) {
    if (_host == (*it)->getServerName()) {
      sb = *it;
      break;
    }
  }
  if (sb == NULL) sb = *(serverBlockList->begin());

  // 요청 호스트와 일치하는 가상호스트가 있다면 그 가상호스트에 있는
  // 로케이션블락을 찾아옴, 해당되는 로케이션 블락이 없으면 서버블락
  // 받아옴
  if (locationMap.find(sb) == locationMap.end())
    _locBlock = sb;
  else {
    _locList = locationMap[sb];
    for (LocationList::iterator it = _locList->begin(); it != _locList->end();
         it++) {
      if (requestURI.find((*it)->getPath()) != requestURI.npos) {
        addHeader("CuttedURI",
                  requestURI.erase(1, (*it)->getPath().length() - 1));
        _locBlock = *it;
        break;
      }
    }
  }
  addHeader("RootDir", _locBlock->getRoot());
  addHeader("AutoIndex", _locBlock->getAutoindex());
  addHeader("Index", _locBlock->getIndex());
  addHeader("Name", _locBlock->getServerName());
  addHeader("Port", ftItos(_locBlock->getListenPort()));
  addHeader("Cgi", _locBlock->getCgi());
  addHeader("Cgi_Redir", _locBlock->getCgiRedir());
};

void Request::setAutoindex(std::string &value) { _autoindex = value; }

void Request::clear() {
  _rawContents.clear();
  std::string clientIp = _header["ClientIP"];
  _header.clear();
  _header["ClientIP"] = clientIp;
  _body.clear();
  _host.clear();
  _mime = "text/html";
  _status = 200;
  _isFullReq = false;
  _isChunked = false;
  _chunkedSize = 0;
  _isFullHeader = false;
}

void Request::addRawContents(const char *raw, size_t size) {
  _rawContents.append(raw, size);
}

void Request::setMime() {
  struct stat info;
  std::string fullUri = _locBlock->getRoot();
  fullUri += _header["CuttedURI"];
  size_t lastDotPos = fullUri.rfind('.');

  if (lastDotPos != std::string::npos) {
    std::string mime = fullUri.substr(lastDotPos + 1);
    if (_mimeTypes.find(mime) != _mimeTypes.end())
      _mime = _mimeTypes[mime];
    else
      _mime = _mimeTypes["else"];
  } else {
    if (stat(fullUri.c_str(), &info) != 0) {
      if (fullUri.back() != '/') {
        std::string requestURI = _header["RawURI"].substr(0).append("/");
        for (LocationList::iterator it = _locList->begin();
             it != _locList->end(); it++) {
          if (requestURI.find((*it)->getPath()) != requestURI.npos) {
            requestURI.erase(1, (*it)->getPath().length() - 1);
            if (requestURI.back() == '/')
              requestURI.erase(requestURI.length() - 1);
            addHeader("CuttedURI", requestURI);
            _locBlock = *it;
            fullUri = _locBlock->getRoot() + _header["CuttedURI"];
            break;
          }
        }
        if (stat(fullUri.c_str(), &info) == 0 && S_ISDIR(info.st_mode)) {
          _mime = _mimeTypes["directory"];
          return;
        }
      }
      if (getMethod() != "PUT") _status = 404;
      return;
    } else if (S_ISDIR(info.st_mode)) {
      _mime = _mimeTypes["directory"];
    } else
      _mime = _mimeTypes["else"];
  }
}

void Request::addHeader(std::string key, std::string value) {
  _header[key] = value;
}

const std::string &Request::getUri() { return _header["URI"]; }

const std::string &Request::getHost() { return _host; }

std::string &Request::getBody() { return _body; }

ServerBlock *Request::getLocBlock() const { return _locBlock; }

const std::string &Request::getAutoindex() const { return _autoindex; }

enum PROCESS Request::getProcess() { return CGI; }

const int &Request::getStatus() const { return _status; }

const std::string &Request::getMime() const { return _mime; }

const std::string &Request::getMethod() { return _header["Method"]; }

bool Request::isFullReq() const { return _isFullReq; }

const std::string &Request::getRawContents() const { return _rawContents; }

const std::string &Request::getHeaderByKey(std::string key) {
  return _header[key];
}

std::map<std::string, std::string> Request::getHeaderMap() const {
  return _header;
}
