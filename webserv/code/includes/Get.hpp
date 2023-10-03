#ifndef GET_HPP
#define GET_HPP

#include "ErrorException.hpp"
#include "Method.hpp"

class Get : public Method {
 private:
  void makeBody(Response &response, std::ifstream &file);
  void makeHeader(Request &request, Response &response);
  void makeResponse(Request &request, Response &response, std::ifstream &file);

 public:
  Get();
  ~Get();

  void process(Request &request, Response &response);
};

#endif
