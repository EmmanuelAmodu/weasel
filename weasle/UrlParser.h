#include <string>
#include <unordered_map>
#include <vector>

class UrlParser
{
public:
  UrlParser(std::string url);
  std::unordered_map<std::string, std::string> matchDynamicPath(std::vector<std::string>);

  const std::string host;
  const std::unordered_map<std::string, std::string> queryParams;
  const std::vector<std::string> path;
  std::unordered_map<std::string, std::string> pathParams;
};
