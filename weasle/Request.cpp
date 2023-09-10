#include "Request.h"

Request::Request()
{
}

Request::Request(char buffer[])
{
  parse(buffer);
}

void Request::parse(char buffer[])
{
  // std::cout << "Received request:\n" << buffer << std::endl;
  std::string temp = "";
  convertBufferToVector(buffer);
  parseRequestDefinition();
  parseHeaders();
  parseBody();
}

void Request::convertBufferToVector(char buffer[])
{
  // Null-terminate the string
  buffer[2047] = '\0';
  std::string temp = "";
  for (int i = 0; i < 2048; i++)
  {
    if (buffer[i] == '\n')
    {
      bufferVector.push_back(temp);
      temp = "";
    }
    else
    {
      temp += buffer[i];
    }
  }
}

void Request::parseRequestDefinition()
{
  std::string line = bufferVector[0];

  size_t methodEnd = line.find(' ');
  if (methodEnd == std::string::npos)
  {
    std::cerr << "Error parsing Methods, Invalid Request" << std::endl;
    exit(1);
  }
  method = line.substr(0, methodEnd);

  // Parse the path
  size_t pathEnd = line.find(' ', methodEnd + 1);
  if (pathEnd == std::string::npos)
  {
    std::cerr << "Error parsing request path, Invalid Request" << std::endl;
    exit(1);
  }
  path = line.substr(methodEnd + 1, pathEnd - methodEnd - 1);

  // Parse the HTTP version
  size_t versionEnd = line.find('\r', pathEnd + 1);
  if (versionEnd == std::string::npos)
  {
    std::cerr << "Error parsing http versions, Invalid Request" << std::endl;
    exit(1);
  }
  version = line.substr(pathEnd + 1, versionEnd - pathEnd - 1);
}

void Request::parseHeaders()
{
  int length = bufferVector.size();
  for (int i = 1; i < length - 1; i++)
  {
    line = bufferVector[i];
    size_t colonPos = line.find(':');
    if (colonPos == std::string::npos)
    {
      std::cerr << "Error paring request header, Invalid Request "  << i << std::endl;
      break;
    }
    std::string key = line.substr(0, colonPos);
    std::string value = line.substr(colonPos + 1, line.length() - colonPos - 2);
    headers[key] = value;
    headersKeys.push_back(key);
    headersValues.push_back(value);
  }
}

void Request::parseBody()
{
  int length = bufferVector.size();
  body = bufferVector[length - 1];
}
