#include <iostream>
#include <string>
#include <unordered_map>
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
        std::unordered_map<std::string,
        std::string> headers
      ) : status(status), body(body), headers(headers) {};

    ResponseCode status;
    std::string body;
    std::unordered_map<std::string, std::string> headers;

    std::string toString();

    static Response * make(std::string body);
    static Response * make(std::string body, ResponseCode status);
    static Response * make(
      std::unordered_map<std::string, std::string> headers,
      std::string body,
      ResponseCode status
    );

  private:
    static Response * makeDefault(std::string body);
};
