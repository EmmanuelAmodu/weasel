#include <string>
#include "Utils.h"

std::string Utils::trim(const std::string &str)
{
  size_t first = str.find_first_not_of(" \t\n\r\f\v");
  size_t last = str.find_last_not_of(" \t\n\r\f\v");

  if (first == std::string::npos) return "";
  return str.substr(first, last - first + 1);
}

Json::Value Utils::queryParamsToJSON(std::string str)
{
  Json::Value root;
  std::vector<std::string> pairs;
  std::string temp = "";
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '&')
    {
      pairs.push_back(temp);
      temp = "";
    }
    else
    {
      temp += str[i];
    }
  }

  pairs.push_back(temp);

  for (int i = 0; i < pairs.size(); i++)
  {
    std::string pair = pairs[i];
    std::string key = pair.substr(0, pair.find('='));
    std::string value = pair.substr(pair.find('=') + 1, pair.length() - pair.find('=') - 1);
    root[key] = value;
  }

  return root;
}

std::vector<std::string> Utils::split(std::string str, char delimiter)
{
  std::vector<std::string> result;
  std::string temp = "";
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == delimiter)
    {
      result.push_back(temp);
      temp = "";
    }
    else
    {
      temp += str[i];
    }
  }

  result.push_back(temp);
  return result;
}
