#include "./weasle/Server.h"
#include "./weasle/Router.h"
#include "./weasle/HttpStatus.h"

int main()
{
  Router* router{};
  router->addRoute("/", std::make_pair(std::vector<std::function<Request *(Request *)>>{}, [](Request *request) -> Response * {
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
  }));

  Server server{router};
  server.startServer();
  return 0;
}
