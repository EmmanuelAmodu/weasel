#include "Router.h"

Router::Router()
{
}

Router *Router::addRoute(
    HttpMethodEnum method,
    std::string path,
    std::function<Response *(Request *)> funcToExecute)
{
  std::string routePath  = registerPath(method, path);
  routes[routePath] = {
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
  std::string routePath  = registerPath(method, path);
  routes[routePath] = {
      middlewares,
      funcToExecute,
  };
  return this;
}

std::string Router::registerPath(HttpMethodEnum method, std::string path)
{
  std::string pathWithMethod = HttpMethod::httpMethodToString.at(method) + " - " + path;
  if (path.find("/:") != std::string::npos)
  {
    dynamicPath[path] = Utils::split(path, '/');
  }

  return pathWithMethod;
}

std::pair<std::string, std::unordered_map<std::string, std::string>> Router::getDynamicPath(std::string route)
{
  std::pair<std::string, std::unordered_map<std::string, std::string>> result = {"", {}};
  auto routeVec = Utils::split(route, '/');
  std::unordered_map<std::string, bool> routeSegmentMap;
  for (auto rSeg : routeVec)
    routeSegmentMap[rSeg] = true;

  std::pair<std::string, int> matchingPath;

  int pathPartCount = routeVec.size();
  for (auto path : dynamicPath)
  {
    if (pathPartCount == path.second.size())
    {
      int matchingSegment = 0;
      for (auto pSeg : path.second)
      {
        if (routeSegmentMap[pSeg] && pSeg.size() > 0)
          matchingSegment++;
      }

      if (matchingSegment > matchingPath.second)
      {
        matchingPath.first = path.first;
        matchingPath.second = matchingSegment;
      }
    }
  }

  result.first = matchingPath.first;
  auto pathsVector = dynamicPath[matchingPath.first];
  for (size_t i = 0; i < pathsVector.size(); i++)
  {
    if (!routeSegmentMap[pathsVector[i]])
      result.second[pathsVector[i]] = routeVec[i];
  }

  return result;
}

std::pair<
    std::vector<std::function<Request *(Request *)>>,
    std::function<Response *(Request *)>>
Router::getRoute(Request *request)
{
  std::string pathWithMethod = HttpMethod::httpMethodToString.at(request->method) + " - " + request->path;
  if (routes.find(pathWithMethod) != routes.end())
  {
    return routes[pathWithMethod];
  }

  auto dynamicPathData = getDynamicPath(request->path);
  if (dynamicPathData.first.size() > 0)
  {
    request->setPathParams(dynamicPathData.second);
    pathWithMethod = HttpMethod::httpMethodToString.at(request->method) + " - " + dynamicPathData.first;
    if (routes.find(pathWithMethod) != routes.end())
    {
      return routes[pathWithMethod];
    }
  }

  return this->handleNotFound();
}

std::pair<
    std::vector<
        std::function<Request *(Request *)>>,
    std::function<Response *(Request *)>>
Router::handleNotFound()
{
  if (notFoundController.second != nullptr)
    return notFoundController;

  return {
      {},
      [](Request *request) -> Response *
      {
        Response *response = new Response();
        response->status = HttpStatus::Not_Found;
        response->body = "Not found";
        response->headers = {
            {"Content-Type", "text/plain"},
        };

        int bodyLen = response->body.length();
        response->headers["Content-Length"] = std::to_string(bodyLen);
        return response;
      }};
}
