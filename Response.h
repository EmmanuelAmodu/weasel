#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "./HttpStatus.h"

struct Response {
  ResponseCode status;
  std::string body;
  std::vector<std::string> headers;
  std::string to_string();
};
