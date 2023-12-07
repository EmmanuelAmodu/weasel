#include <iostream>
#include <string>
#include <thread>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/time.h>
#include <cerrno>
#include <unordered_map>
#include <vector>
#include "Server.h"
#include "./HttpStatus.h"

Server::Server(Router *router)
{
  this->router = router;
}

void Server::handleConnection(int client_sock)
{
  struct timeval timeout;
  timeout.tv_sec = 60;
  timeout.tv_usec = 0;
  setsockopt(client_sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
  setsockopt(client_sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));

  while (true)
  {
    Request* request = getRequestObject(client_sock);
    if (request != nullptr) {
      Response* response = processRequest(request);
      std::string responseString = response->toString();
      ssize_t bytesWritten = write(client_sock, responseString.c_str(), responseString.size());
      delete response;
      delete request;

      if (bytesWritten < 0)
      {
        std::cerr << "Write failed" << std::endl;
        return;
      }
    } else if (
      request == nullptr ||
      request->headers["Connection"].empty() ||
      request->headers["Connection"].find("keep-alive") == std::string::npos)
    {
      delete request;
      close(client_sock);
      return;
    } else {
      delete request;
    }
  }
}

Request* Server::getRequestObject(int client_sock)
{
  char buffer[2048] = {0};
  ssize_t bytesRead = read(client_sock, buffer, 2047);

  if (bytesRead < 0)
  {
    if (errno == EWOULDBLOCK)
    {
      std::cerr << "Timeout occurred" << std::endl;
    }
    else
    {
      std::cerr << "Read failed with error code: " << errno << std::endl;
    }

    return nullptr;
  }
  else if (bytesRead == 0)
  {
    std::cerr << "Client disconnected" << std::endl;
    return nullptr;
  }

  return new Request(buffer);
}

void Server::listenForConnections()
{
  while (true)
  {
    struct sockaddr_in client_address;
    socklen_t client_len = sizeof(client_address);
    int client_sock = accept(sockfd, (struct sockaddr *)&client_address, &client_len);

    if (client_sock == -1)
    {
      std::cerr << "Accept failed";
      continue;
    }

    std::thread client_thread([this, client_sock]
                              { this->handleConnection(client_sock); });
    client_thread.detach();
  }
}

Response *Server::processRequest(Request *request)
{
  auto controller = router->getRoute(request->method, request->path);
  if (controller.first.size() > 0)
  {
    for (auto middleware : controller.first)
    {
      request = middleware(request);
    }
  }

  return controller.second(request);
}

void Server::startServer()
{
  int sockfd = bindSocket();
  if (sockfd != -1)
    listenForConnections();
}

int Server::bindSocket()
{
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd == -1)
  {
    std::cerr << "Failed to create socket";
    return -1;
  }

  sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(8080);
  server_address.sin_addr.s_addr = INADDR_ANY;

  if (bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
  {
    std::cerr << "Bind failed";
    return -1;
  }

  if (listen(sockfd, 10) == -1)
  {
    std::cerr << "Listen failed";
    return -1;
  }

  std::cout << "Server running on port 8080" << std::endl;
  return sockfd;
}
