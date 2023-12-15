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

void Server::handleConnection(int clientSock)
{
  struct timeval timeout;
  timeout.tv_sec = 60;
  timeout.tv_usec = 0;
  setsockopt(clientSock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
  setsockopt(clientSock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));

  while (true)
  {
    Request* request = getRequestObject(clientSock);
    if (request != nullptr) {
      Response* response = processRequest(request);
      std::string responseString = response->toString();
      ssize_t bytesWritten = write(clientSock, responseString.c_str(), responseString.size());
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
      close(clientSock);
      return;
    } else {
      delete request;
    }
  }
}

Request* Server::getRequestObject(int clientSock)
{
  char buffer[2048] = {0};
  ssize_t bytesRead = read(clientSock, buffer, 2047);

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
    struct sockaddr_in clientAddress;
    socklen_t clientLen = sizeof(clientAddress);
    int clientSock = accept(sockfd, (struct sockaddr *)&clientAddress, &clientLen);

    if (clientSock == -1)
    {
      std::cerr << "Accept failed";
      continue;
    }

    std::thread clientThread([this, clientSock]
                              { this->handleConnection(clientSock); });
    clientThread.detach();
  }
}

Response *Server::processRequest(Request *request)
{
  auto controller = router->getRoute(request);
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
  bindSocket();
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

  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(8080);
  serverAddress.sin_addr.s_addr = INADDR_ANY;

  if (bind(sockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1)
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
