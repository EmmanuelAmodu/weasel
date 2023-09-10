#include <map>
#include <string>
#include <functional>
#include <vector>

#include "./Request.h"
#include "./Response.h"

#pragma once

class Router
{
public:
  Router();
  Router* addRoute(
      std::string,
      std::pair<
          std::vector<std::function<Request *(Request *)>>,
          std::function<Response *(Request *)>>);

  std::pair<
    std::vector<
        std::function<Request *(Request *)>>,
    std::function<Response *(Request *)>>
    getRoute(std::string);

private:
  std::map<
      std::string,
      std::pair<
          std::vector<std::function<Request *(Request *)>>,
          std::function<Response *(Request *)>>>
      routes;
};
