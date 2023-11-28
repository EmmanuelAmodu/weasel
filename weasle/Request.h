#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "./HttpMethod.cpp"

#pragma once

class Request
{
  public:
    Request();
    Request(char buffer[]);
    // ~Request();
    void parse(char buffer[]);
    HttpMethod method;
    std::string path;
    std::string version;
    std::unordered_map<std::string, std::string> headers;
    std::vector<std::string> headersKeys;
    std::vector<std::string> headersValues;
    std::string body;

  private:
    std::vector<std::string> bufferVector;
    std::string line;
    size_t methodEnd;
    size_t pathEnd;
    size_t versionEnd;
    void convertBufferToVector(char buffer[]);
    void parseRequestDefinition();
    void parseHeaders();
    void parseBody();
};
