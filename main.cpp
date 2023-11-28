#include "./weasle/Server.h"
#include "./weasle/Router.h"
#include "./weasle/HttpStatus.h"

int main()
{
  Router* router = new Router();
  router->addRoute("/", 
  std::pair<std::vector<std::function<Request *(Request *)>>, std::function<Response *(Request *)>> {
    {},
    [](Request *request) -> Response * {
      Response *response = new Response();
      response->status = HttpStatus::OK;
      response->body = "Hello, World!";
      response->headers = {
          {"Content-Type", "text/plain"},
          {"Connection", "keep-alive"},
      };

      int bodyLen = response->body.length();
      response->headers["Content-Length"] = std::to_string(bodyLen);
      return response;
    }
  });

  Server server{router};
  server.startServer();
  delete router;
  return 0;
}
