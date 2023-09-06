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

struct Request
{
  std::string method;
  std::string path;
  std::string version;
  std::map<std::string, std::string> headers;
  std::vector<std::string> headersKeys;
  std::vector<std::string> headersValues;
  std::string body;
};

Request parseRequest(char buffer[])
{
  Request request;
  buffer[2047] = '\0'; // Null-terminate the string
  // std::cout << "Received request:\n" << buffer << std::endl;

  // convert buffer to vector of strings serated by \n
  std::vector<std::string> bufferVector;
  std::string temp = "";
  for (int i = 0; i < 2048; i++)
  {
    if (buffer[i] == '\n')
    {
      bufferVector.push_back(temp);
      temp = "";
    }
    else
    {
      temp += buffer[i];
    }
  }

  std::string line = bufferVector[0];

  size_t methodEnd = line.find(' ');
  if (methodEnd == std::string::npos)
  {
    std::cerr << "Error parsing Methods, Invalid Request" << std::endl;
    exit(1);
  }
  request.method = line.substr(0, methodEnd);

  // Parse the path
  size_t pathEnd = line.find(' ', methodEnd + 1);
  if (pathEnd == std::string::npos)
  {
    std::cerr << "Error parsing request path, Invalid Request" << std::endl;
    exit(1);
  }
  request.path = line.substr(methodEnd + 1, pathEnd - methodEnd - 1);

  // Parse the HTTP version
  size_t versionEnd = line.find('\r', pathEnd + 1);
  if (versionEnd == std::string::npos)
  {
    std::cerr << "Error parsing http versions, Invalid Request" << std::endl;
    exit(1);
  }
  request.version = line.substr(pathEnd + 1, versionEnd - pathEnd - 1);

  // Parse the headers
  int length = bufferVector.size();
  for (int i = 1; i < length - 1; i++)
  {
    line = bufferVector[i];
    size_t colonPos = line.find(':');
    if (colonPos == std::string::npos)
    {
      std::cerr << "Error paring request header, Invalid Request" << std::endl;
      exit(1);
    }
    std::string key = line.substr(0, colonPos);
    std::string value = line.substr(colonPos + 1, line.length() - colonPos - 2);
    request.headers[key] = value;
    request.headersKeys.push_back(key);
    request.headersValues.push_back(value);
  }

  // Parse the body
  request.body = bufferVector[length - 1];

  return request;
}

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
      Request request = parseRequest(buffer);
      std::cout << "Request parsed" << std::endl;
      std::cout << "Method: " << request.method << std::endl;
      std::cout << "Path: " << request.path << std::endl;
      std::cout << "Version: " << request.version << std::endl;
      std::cout << "Headers: " << std::endl;
      for (int i = 0; i < request.headersKeys.size(); i++)
      {
        std::cout << request.headersKeys[i] << ": " << request.headersValues[i] << std::endl;
      }

      std::cout << "Body: " << request.body << std::endl;
    }

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
