#ifndef IMETHOD_HPP
#define IMETHOD_HPP

#include <fstream>
#include <iostream>
#include <sstream>

#include "Cgi.hpp"
#include "ErrorException.hpp"
#include "Request.hpp"
#include "Response.hpp"
#include "Utils.hpp"

class IMethod {
 public:
  virtual ~IMethod(){};
  virtual void process(Request &request, Response &response) = 0;
};

#endif
