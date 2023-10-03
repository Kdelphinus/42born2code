#include "../includes/Delete.hpp"

void Delete::makeStatusLine(Request &request, Response &response) {
  std::string fullUri = request.getHeaderByKey("RootDir");
  fullUri += request.getHeaderByKey("CuttedURI");
  if (fullUri[(fullUri.size() - 1)] == '/') {
    if (request.getHeaderByKey("Index") != "") {
      std::stringstream ss(request.getHeaderByKey("Index"));
      std::string token;

      while (ss >> token) {
        std::ifstream temp(fullUri.substr().append(token).c_str());
        if (temp.is_open() == true) {
          if (remove(fullUri.substr().append(token).c_str()) == 0) {
            response.setStatusLine(204);
            return;
          } else {
            response.setErrorRes(403);
            return;
          }
        }
      }
    }
    std::ifstream tmp(fullUri.substr().append("index.html").c_str());
    if (tmp.is_open() == true) {
      remove(fullUri.substr().append("index.html").c_str());
      response.setStatusLine(204);
      return;
    } else  // pure directory
      response.setErrorRes(404);
  } else {
    std::ifstream tempf(fullUri.substr().c_str());
    if (tempf.is_open() == true) {
      if (remove(fullUri.substr().c_str()) == 0) {
        response.setStatusLine(204);
        return;
      } else {
        response.setErrorRes(403);
        return;
      };
    } else  // file not found or can't open
      response.setErrorRes(404);
  }
}

void Delete::process(Request &request, Response &response) {
  makeStatusLine(request, response);
  response.setResult();
}

Delete::Delete() {}

Delete::~Delete() {}
