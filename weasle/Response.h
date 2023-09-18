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
    Response(
      ResponseCode status,
      std::string body,
      std::map<std::string,
      std::string> headers
    ) : status(status), body(body), headers(headers);

    ResponseCode status;
    std::string body;
    std::map<std::string, std::string> headers;

    std::string getResponseString();
};
