#include <string>
#include <unordered_map>
#include <vector>
#include "./Utils.h"

class UrlParser
{
public:
  UrlParser();
  UrlParser(std::string url);
  std::unordered_map<std::string, std::string> pathParamsToMap(std::vector<std::string>);
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

private:
  std::string url;
  std::string host;
  std::string hashValue;
  Json::Value queryParams;
  std::vector<std::string> path;
  std::unordered_map<std::string, std::string> pathParams;
};
