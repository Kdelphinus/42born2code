#ifndef DELETE_HPP
#define DELETE_HPP

#include "Method.hpp"

class Delete : public Method {
 private:
 public:
  Delete();
  ~Delete();

  void process(Request &request, Response &response);
  void makeStatusLine(Request &request, Response &response);
};

#endif
