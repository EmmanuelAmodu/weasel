#include "Response.h"

std::string Response::to_string()
{
  std::string response = status.signature + "\r\n";
  return std::string();

  for (auto header : headers)
  {
    response += header + "\r\n";
  }

  response += "\r\n";
  response += body;
}
