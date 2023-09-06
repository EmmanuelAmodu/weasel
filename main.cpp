#include <iostream>
#include <string>
#include <thread> // For std::thread
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/time.h>
#include <cerrno>
#include <map>
#include <vector>
#include "./Request.h"


void handleConnection(int client_sock)
{
  // Set up a timeout of 10 seconds
  struct timeval timeout;
  timeout.tv_sec = 60;
  timeout.tv_usec = 0;
  setsockopt(client_sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
  setsockopt(client_sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));

  while (true) // Keep the connection open
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
      close(client_sock);
      return;
    }
    else if (bytesRead == 0)
    {
      std::cerr << "Client disconnected" << std::endl;
      close(client_sock);
      return;
    }
    else
    {
      Request request(buffer);

      std::string response = "HTTP/1.1 200 OK\r\n"
                             "Content-Type: text/plain\r\n"
                             "Content-Length: 12\r\n"
                             "Connection: keep-alive\r\n"
                             "\r\n"
                             "Hello World!";

      ssize_t bytesWritten = write(client_sock, response.c_str(), response.size());

      if (bytesWritten < 0)
      {
        std::cerr << "Write failed" << std::endl;
        close(client_sock);
        return;
      }
    }
  }
}

int main()
{
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd == -1)
  {
    std::cerr << "Failed to create socket";
    return -1;
  }

  struct sockaddr_in server_address;
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

    std::thread client_thread(handleConnection, client_sock);
    client_thread.detach();
  }

  return 0;
}
