#include <unordered_map>
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
  Router(std::pair<
         std::vector<
             std::function<Request *(Request *)>>,
         std::function<Response *(Request *)>> notFoundController) : notFoundController(notFoundController){};
  
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
  std::pair<
      std::vector<
          std::function<Request *(Request *)>>,
      std::function<Response *(Request *)>>
      notFoundController;

  std::unordered_map<
      std::string,
      std::pair<
          std::vector<std::function<Request *(Request *)>>,
          std::function<Response *(Request *)>>>
      routes;

  std::pair<
      std::vector<
          std::function<Request *(Request *)>>,
      std::function<Response *(Request *)>>
      handleNotFound();
};
