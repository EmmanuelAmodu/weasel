#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <json/json.h>

#include "./HttpMethod.h"
#include "./Utils.h"

#pragma once

class Request
{
  public:
    Request();
    Request(char buffer[]);
    // ~Request();
    void parse(char buffer[]);
    HttpMethodEnum method;
    std::string path;
    std::string version;
    std::unordered_map<std::string, std::string> headers;
    std::vector<std::string> headersKeys;
    std::vector<std::string> headersValues;
    std::string body;
    Json::Value json();

  private:
    std::vector<std::string> bufferVector;
    std::string line;
    int methodEnd;
    int pathEnd;
    int versionEnd;
    int headerEndIndex;
    void convertBufferToVector(char buffer[]);
    void parseRequestDefinition();
    void parseHeaders();
    void parseBody();
};
