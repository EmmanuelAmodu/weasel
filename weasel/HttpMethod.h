#pragma once

#include <unordered_map>
#include <string>

enum HttpMethodEnum
{
  POST,
  GET,
  PATCH,
  DELETE,
  HEAD,
  PUT,
  CONNECT,
  OPTIONS,
  TRACE
};

class HttpMethod
{
public:
    static const HttpMethodEnum POST;
    static const HttpMethodEnum GET;
    static const HttpMethodEnum PATCH;
    static const HttpMethodEnum DELETE;
    static const HttpMethodEnum HEAD;
    static const HttpMethodEnum PUT;
    static const HttpMethodEnum CONNECT;
    static const HttpMethodEnum OPTIONS;
    static const HttpMethodEnum TRACE;

    static const std::unordered_map<HttpMethodEnum, std::string> httpMethodToString;
    static const std::unordered_map<std::string, HttpMethodEnum> httpStringToMethod;
};
