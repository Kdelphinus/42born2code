#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <string.h>
#include <sys/dir.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <map>

#include "Request.hpp"
#include "Utils.hpp"

class Response {
 private:
  std::map<std::string, std::string> _headers;
  std::string _body;
  std::string _statusLine;
  char *_result;
  size_t _resultSize;
  size_t _sendCnt;
  std::map<int, std::string> _statusCodes;

 public:
  Response();
  ~Response();

  void directoryListing(std::string path);
  void convertCGI(const std::string &cgiResult);
  int sendResponse(int clientSocket);

  bool isInHeader(const std::string &key);

  const std::string &getBody() const;
  void setRedirectRes(int statusCode);
  void setErrorRes(int statusCode);
  void setResult();
  void setStatusLine(int code);
  void setHeaders(const std::string &key, const std::string &value);
  void setBody(std::stringstream &buffer);
  bool isFullWrite() const;
};

#endif