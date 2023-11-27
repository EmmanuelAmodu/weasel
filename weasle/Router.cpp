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
  if (routes.find(path) != routes.end())
    return routes[path];

  return this->handleNotFound();
}

std::pair<std::vector<std::function<Request *(Request *)>>, std::function<Response *(Request *)>> Router::handleNotFound()
{
  if (notFoundController .second != nullptr)
    return notFoundController;

  return std::pair<std::vector<std::function<Request *(Request *)>>, std::function<Response *(Request *)>>({}, [](Request *request) -> Response * {
    Response *response = new Response();
    response->status = HttpStatus::Not_Found;
    response->body = "Not found";
    response->headers = {
      {"Content-Type", "text/plain"},
    };

    int bodyLen = response->body.length();
    response->headers["Content-Length"] = std::to_string(bodyLen);
    return response;
  });
}
