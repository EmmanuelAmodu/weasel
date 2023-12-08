#include <string>
#include "Utils.h"

std::string Utils::trim(const std::string &str)
{
  size_t first = str.find_first_not_of(" \t\n\r\f\v");
  size_t last = str.find_last_not_of(" \t\n\r\f\v");

  if (first == std::string::npos) return "";
  return str.substr(first, last - first + 1);
}
