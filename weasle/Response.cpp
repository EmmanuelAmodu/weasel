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
