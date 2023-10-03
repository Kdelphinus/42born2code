#include "../includes/Get.hpp"

Get::Get() {}

Get::~Get() {}

void Get::makeBody(Response &response, std::ifstream &file) {
  std::stringstream buffer;

  buffer << file.rdbuf();
  file.close();
  if (buffer.good() == false) throw ErrorException(500);
  response.setBody(buffer);
  return;
}

void Get::makeHeader(Request &request, Response &response) {
  if (response.getBody() != "")
    if (response.isInHeader("Content-Type") == false) {
      response.setHeaders("Content-Type", request.getMime());
    }
  response.setHeaders("Content-Length", ftItos(response.getBody().size()));
}

void Get::makeResponse(Request &request, Response &response,
                       std::ifstream &file) {
  makeBody(response, file);
  makeHeader(request, response);
  response.setStatusLine(request.getStatus());
  response.setResult();
}

void Get::process(Request &request, Response &response) {
  try {
    std::string fullUri = request.getHeaderByKey("RootDir");
    fullUri += request.getHeaderByKey("CuttedURI");
    if (fullUri.back() == '/') {
      if (request.getHeaderByKey("Index") != "") {
        std::stringstream ss(request.getHeaderByKey("Index"));
        std::string token;

        while (ss >> token) {
          std::ifstream temp(fullUri.substr().append(token).c_str());
          if (temp.is_open() == true) {
            _path = fullUri.substr().append(token).c_str();
            makeResponse(request, response, temp);
            return;
          }
        }
      }
      std::ifstream tmp(fullUri.substr().append("index.html").c_str());
      if (tmp.is_open() == true) {
        _path = fullUri.substr().append("index.html").c_str();
        makeResponse(request, response, tmp);
        return;
      }
      if (request.getHeaderByKey("AutoIndex") == "on")
        response.directoryListing(fullUri);
      else
        throw ErrorException(404);
    } else if (request.getMime() == "directory") {
      std::string tmp = request.getHeaderByKey("RawURI");
      tmp += "/";
      response.setHeaders("Location", tmp);
      throw ErrorException(301);
    } else {
      std::ifstream tempf(fullUri.c_str());
      if (tempf.is_open() == true) {
        _path = fullUri.c_str();
        makeResponse(request, response, tempf);
        return;
      } else
        throw ErrorException(404);
    }
  } catch (ErrorException &e) {
    if (e.getErrorCode() >= 400) {
      response.setErrorRes(e.getErrorCode());
    } else {
      response.setRedirectRes(e.getErrorCode());
    }
  }
}
