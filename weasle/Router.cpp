#include "Router.h"

Router::Router()
{
}

Router* Router::addRoute(
  HttpMethodEnum method,
  std::string path,
  std::function<Response *(Request *)> funcToExecute
)
{
  std::string pathWithMethod = HttpMethod::httpMethodToString.at(method) + " - " + path;
  routes[pathWithMethod] = {
    {},
    funcToExecute,
  };
  return this;
}

Router *Router::addRoute(
  HttpMethodEnum method,
  std::string path,
  std::vector<std::function<Request *(Request *)>> middlewares,
  std::function<Response *(Request *)> funcToExecute)
{
  std::string pathWithMethod = HttpMethod::httpMethodToString.at(method) + " - " + path;
  routes[pathWithMethod] = {
    middlewares,
    funcToExecute,
  };
  return this;
}

std::pair<
  std::vector<std::function<Request *(Request *)>>,
  std::function<Response *(Request *)>>
Router::getRoute(HttpMethodEnum method, std::string path)
{
  std::string pathWithMethod = HttpMethod::httpMethodToString.at(method) + " - " + path;
  if (routes.find(pathWithMethod) != routes.end())
    return routes[pathWithMethod];

  return this->handleNotFound();
}

std::pair<std::vector<std::function<Request *(Request *)>>, std::function<Response *(Request *)>> Router::handleNotFound()
{
  if (notFoundController.second != nullptr)
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
