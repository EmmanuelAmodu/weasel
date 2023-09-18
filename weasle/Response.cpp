#include "Response.h"

Response::Response()
{
}

Response::Response(ResponseCode status, std::string body, std::map<std::string, std::string> headers)
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
