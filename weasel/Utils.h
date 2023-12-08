#include <string>
#include <json/json.h>

#pragma once

class Utils {
public:
  static std::string trim(const std::string&);
  static Json::Value queryParamsToJSON(std::string);
  static std::vector<std::string> split(std::string, char);
};
