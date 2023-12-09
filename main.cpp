#include "./weasel/Server.h"
#include "./weasel/Router.h"
#include "./weasel/HttpStatus.h"
#include "./weasel/HttpMethod.h"

int main()
{
  Router *router = new Router();
  router
      ->addRoute(
          HttpMethod::GET,
          "/",
          [](Request *request) -> Response *
          {
            return Response::make("THIS IS THE ROOT PATH GET METHOD");
          })
      ->addRoute(
          HttpMethod::POST,
          "/",
          [](Request *request) -> Response *
          {
            return Response::make("THIS IS THE ROOT PATH POST METHOD");
          })
      ->addRoute(
          HttpMethod::GET,
          "/:custom",
          [](Request *request) -> Response *
          {
            auto pathParams = request->getUrl().getPathParams();
            for (auto params : pathParams)
            {
              std::cout << "Path Params Values " << params.first << ": " << params.second << std::endl;
            }
            
            return Response::make("THIS IS THE ROOT PATH POST METHOD");
          });

  Server server{router};
  server.startServer();
  delete router;
  return 0;
}
