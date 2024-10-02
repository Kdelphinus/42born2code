#ifndef METHOD_HPP
#define METHOD_HPP

#include "IMethod.hpp"

class Method : public IMethod {
 private:
 protected:
  std::string _path;

 public:
  virtual ~Method();
  virtual void process(Request &request, Response &response);
};

#endif
