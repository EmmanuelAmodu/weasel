#include "Router.h"

Router::Router()
{
}

Router* Router::addRoute(std::string path, std::pair<std::vector<std::function<Request *(Request *)>>, std::function<Response *(Request *)>> methods)
{
  routes[path] = methods;
  return this;
}

std::pair<std::vector<std::function<Request *(Request *)>>, std::function<Response *(Request *)>> Router::getRoute(std::string path)
{
  return routes[path];
}
