#include "UrlParser.h"

UrlParser::UrlParser(std::string url) : url(url)
{
  std::string::size_type queryIndex = url.find('?');
  std::string::size_type pathIndex = url.find('/', 8);
  std::string::size_type hashIndex = url.find('#');

  if (queryIndex != std::string::npos)
  {
    std::string queryString = url.substr(queryIndex + 1);
    this->queryParams = Utils::queryParamsToJSON(queryString);
  }

  if (pathIndex != std::string::npos)
  {
    std::string pathString = url.substr(pathIndex + 1, queryIndex - pathIndex - 1);
    this->path = Utils::split(pathString, '/');
  }

  if (hashIndex != std::string::npos)
  {
    this->hashValue = url.substr(hashIndex + 1);
  }

  this->host = url.substr(0, pathIndex);
}
