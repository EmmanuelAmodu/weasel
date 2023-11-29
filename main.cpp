#include "./weasle/Server.h"
#include "./weasle/Router.h"
#include "./weasle/HttpStatus.h"
#include "./weasle/HttpMethod.h"

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
          });

  Server server{router};
  server.startServer();
  delete router;
  return 0;
}
