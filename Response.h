#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "./HttpStatus.h"

#pragma once

class Response
{
  public:
    Response();
    ResponseCode status;
    std::string body;
    std::map<std::string, std::string> headers;
};
