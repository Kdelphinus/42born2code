#include "../includes/Method.hpp"

Method::~Method() {}

void Method::process(Request &request, Response &response) {
  (void)request;
  response.setErrorRes(405);
  return;
}
