enum class HttpMethod {
    POST,
    GET,
    PATCH,
    DELETE,
    HEAD,
    PUT,
    CONNECT,
    OPTIONS,
    TRACE
};

const std::unordered_map<HttpMethod, std::string> HttpMethodToString = {
    { HttpMethod::POST, "POST" },
    { HttpMethod::GET, "GET" },
    { HttpMethod::PATCH, "PATCH" },
    { HttpMethod::DELETE, "DELETE" },
    { HttpMethod::HEAD, "HEAD" },
    { HttpMethod::PUT, "PUT" },
    { HttpMethod::CONNECT, "CONNECT" },
    { HttpMethod::OPTIONS, "OPTIONS" },
    { HttpMethod::TRACE, "TRACE" }
};

const std::unordered_map<std::string, HttpMethod> HttpStringToMethod = {
    { "POST", HttpMethod::POST },
    { "GET", HttpMethod::GET },
    { "PATCH", HttpMethod::PATCH },
    { "DELETE", HttpMethod::DELETE },
    { "HEAD", HttpMethod::HEAD },
    { "PUT", HttpMethod::PUT },
    { "CONNECT", HttpMethod::CONNECT },
    { "OPTIONS", HttpMethod::OPTIONS },
    { "TRACE", HttpMethod::TRACE }
};
