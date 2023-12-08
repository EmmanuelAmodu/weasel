#include "Request.h"
#include <algorithm>

Request::Request()
{
}

Request::Request(char buffer[])
{
  parse(buffer);
}

void Request::parse(char buffer[])
{
  convertBufferToVector(buffer);
  parseRequestDefinition();
  parseHeaders();
  url = UrlParser(headers["Host"] + path); 
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

  // std::cout << buffer << std::endl;

  bufferVector.push_back(temp);
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
  method = HttpMethod::httpStringToMethod.at(line.substr(0, methodEnd));

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
    size_t colonPosition = line.find(':');
    if (colonPosition == std::string::npos) {
      headerEndIndex = i;
      break;
    }

    std::string key = line.substr(0, colonPosition);
    std::string value = line.substr(colonPosition + 1, line.length() - colonPosition - 2);
    headers[key] = value;
    headersKeys.push_back(key);
    headersValues.push_back(value);
  }
}

void Request::parseBody()
{
  int length = bufferVector.size();
  for (int i = headerEndIndex + 1; i < length; i++)
  {
    body += Utils::trim(bufferVector[i]);
  }

  if (headers.count("Content-Type") > 0)
  {
    std::string contentType = headers["Content-Type"];
    if (contentType.find("application/json") != std::string::npos)
    {
      bodyType = BodyType::JSON;
      json = processJson();
    }
    else if (contentType.find("application/x-www-form-urlencoded") != std::string::npos)
    {
      bodyType = BodyType::FORM_DATA;
      json = processXForm();
    }
    else
    {
      bodyType = BodyType::TEXT;
    }
  }
  else
  {
    bodyType = BodyType::TEXT;
  }
}

Json::Value Request::processJson()
{
  Json::Value root;
  Json::Reader reader;
  bool parsingSuccessful = reader.parse(body, root);
  if (parsingSuccessful) {
    return root;
  } else {
    throw "Request body not a valid JSON";
  }
}

Json::Value Request::processXForm()
{
  return Utils::queryParamsToJSON(body);
}

void Request::setPathParams(std::unordered_map<std::string, std::string> params)
{
  url.setPathParams(params);
}
