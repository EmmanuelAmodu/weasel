#include <netinet/in.h>
#include "./Request.h"
#include "./Response.h"
#include "./Router.h"

#pragma once

class Server
{
public:
  Server(Router *router);
  void startServer();

private:
  int bindSocket();
  void handleConnection(int);
  Request* getRequestObject(int);
  void listenForConnections();
  Response* processRequest(Request*);
  std::string getResponseString(Response*);
  int sockfd;
  struct sockaddr_in server_address;
  Router *router;
};
