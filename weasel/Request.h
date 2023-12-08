#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <json/json.h>

#include "./HttpMethod.h"
#include "./Utils.h"

#pragma once

enum BodyType
{
  JSON,
  FORM_DATA,
  TEXT
};

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

    const BodyType& getBodyType() const {
      return bodyType;
    }

    const Json::Value& getJson() const {
      return json;
    }

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
    Json::Value processJson();
    Json::Value processXForm();
    BodyType bodyType;
    Json::Value json;
};
