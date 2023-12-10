#include "Response.h"

Response::Response()
{
}

std::string Response::toString()
{
  std::string responseString = status.signature + "\r\n";
  for (auto header : headers)
  {
    responseString += header.first + ": " + header.second + "\r\n";
  }

  responseString += "\r\n";
  responseString += body + "\r\n";
  return responseString;
}

Response *Response::make(std::string body)
{
  return makeDefault(body);
}

Response *Response::make(std::string body, ResponseCode status)
{
  Response *response = makeDefault(body);
  response->status = status;
  return response;
}

Response *Response::make(
    std::unordered_map<std::string, std::string> headers,
    std::string body,
    ResponseCode status)
{
  Response *response = makeDefault(body);
  response->status = status;

  for (auto header : headers)
  {
    response->headers[header.first] = header.second;
  }

  return response;
}

Response *Response::makeFromJson(Json::Value body)
{
  return make(jsonToString(body));
}

Response *Response::makeFromJson(Json::Value body, ResponseCode status)
{
  return make(jsonToString(body), status);
}

Response *Response::makeFromJson(
    std::unordered_map<std::string, std::string> headers,
    Json::Value body,
    ResponseCode status)
{
  return make(headers, jsonToString(body), status);
}

Response *Response::makeDefault(std::string body)
{
  Response *response = new Response();
  response->status = HttpStatus::OK;
  response->body = body;
  response->headers = {
      {"Content-Type", "text/plain"},
      {"Connection", "keep-alive"},
  };

  response->headers["Content-Length"] = std::to_string(body.length());
  return response;
}

std::string Response::jsonToString(Json::Value json)
{
  Json::StreamWriterBuilder builder;
  builder["indentation"] = ""; // If you want whitespace-less output
  return Json::writeString(builder, json);
}
