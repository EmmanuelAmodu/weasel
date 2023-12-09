#include <string>
#include <unordered_map>
#include <vector>
#include "./Utils.h"

class UrlParser
{
public:
  UrlParser();
  UrlParser(std::string url);
  void setPathParams(std::unordered_map<std::string, std::string>);
  void parse();

  const std::string &getHost() const
  {
    return host;
  }

  const Json::Value &getQueryParams() const
  {
    return queryParams;
  }

  const std::vector<std::string> &getPath() const
  {
    return path;
  }

  const std::string &getHashValue() const
  {
    return hashValue;
  }

  const auto &getPathParams() const
  {
    return pathParams;
  }

private:
  std::string url;
  std::string host;
  std::string hashValue;
  Json::Value queryParams;
  std::vector<std::string> path;
  std::unordered_map<std::string, std::string> pathParams;
};
