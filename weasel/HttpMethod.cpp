#include "HttpMethod.h"

const HttpMethodEnum HttpMethod::POST = HttpMethodEnum::POST;
const HttpMethodEnum HttpMethod::GET = HttpMethodEnum::GET;
const HttpMethodEnum HttpMethod::PATCH = HttpMethodEnum::PATCH;
const HttpMethodEnum HttpMethod::DELETE = HttpMethodEnum::DELETE;
const HttpMethodEnum HttpMethod::HEAD = HttpMethodEnum::HEAD;
const HttpMethodEnum HttpMethod::PUT = HttpMethodEnum::PUT;
const HttpMethodEnum HttpMethod::CONNECT = HttpMethodEnum::CONNECT;
const HttpMethodEnum HttpMethod::OPTIONS = HttpMethodEnum::OPTIONS;
const HttpMethodEnum HttpMethod::TRACE = HttpMethodEnum::TRACE;

const std::unordered_map<HttpMethodEnum, std::string> HttpMethod::httpMethodToString = {
  {HttpMethod::POST, "POST"},
  {HttpMethod::GET, "GET"},
  {HttpMethod::PATCH, "PATCH"},
  {HttpMethod::DELETE, "DELETE"},
  {HttpMethod::HEAD, "HEAD"},
  {HttpMethod::PUT, "PUT"},
  {HttpMethod::CONNECT, "CONNECT"},
  {HttpMethod::OPTIONS, "OPTIONS"},
  {HttpMethod::TRACE, "TRACE"}
};

const std::unordered_map<std::string, HttpMethodEnum> HttpMethod::httpStringToMethod = {
  {"POST", HttpMethod::POST},
  {"GET", HttpMethod::GET},
  {"PATCH", HttpMethod::PATCH},
  {"DELETE", HttpMethod::DELETE},
  {"HEAD", HttpMethod::HEAD},
  {"PUT", HttpMethod::PUT},
  {"CONNECT", HttpMethod::CONNECT},
  {"OPTIONS", HttpMethod::OPTIONS},
  {"TRACE", HttpMethod::TRACE}
};
