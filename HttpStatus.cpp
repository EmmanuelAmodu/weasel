#include "HttpStatus.h"

ResponseCode HttpStatus::getResponseCode(int code)
{
  return ResponseCode();
}

std::string HttpStatus::getResponseCodeMessage(int code)
{
  return std::string();
}

std::string HttpStatus::getResponseCodeSignature(int code)
{
  return std::string();
}

const ResponseCode HttpStatus::Continue{100, "Continue", "HTTP/1.1 100 Continue\r\n"};
const ResponseCode HttpStatus::Switching_Protocols{101, "Switching Protocols", "HTTP/1.1 101 Switching Protocols\r\n"};
const ResponseCode HttpStatus::Processing{102, "Processing", "HTTP/1.1 102 Processing\r\n"};
const ResponseCode HttpStatus::OK{200, "OK", "HTTP/1.1 200 OK\r\n"};
const ResponseCode HttpStatus::Created{201, "Created", "HTTP/1.1 201 Created\r\n"};
const ResponseCode HttpStatus::Accepted{202, "Accepted", "HTTP/1.1 202 Accepted\r\n"};
const ResponseCode HttpStatus::Non_Authoritative_Information{203, "Non-Authoritative Information", "HTTP/1.1 203 Non-Authoritative Information\r\n"};
const ResponseCode HttpStatus::No_Content{204, "No Content", "HTTP/1.1 204 No Content\r\n"};
const ResponseCode HttpStatus::Reset_Content{205, "Reset Content", "HTTP/1.1 205 Reset Content\r\n"};
const ResponseCode HttpStatus::Partial_Content{206, "Partial Content", "HTTP/1.1 206 Partial Content\r\n"};
const ResponseCode HttpStatus::Multi_Status{207, "Multi-Status", "HTTP/1.1 207 Multi-Status\r\n"};
const ResponseCode HttpStatus::Already_Reported{208, "Already Reported", "HTTP/1.1 208 Already Reported\r\n"};
const ResponseCode HttpStatus::IM_Used{226, "IM Used", "HTTP/1.1 226 IM Used\r\n"};
const ResponseCode HttpStatus::Multiple_Choices{300, "Multiple Choices", "HTTP/1.1 300 Multiple Choices\r\n"};
const ResponseCode HttpStatus::Moved_Permanently{301, "Moved Permanently", "HTTP/1.1 301 Moved Permanently\r\n"};
const ResponseCode HttpStatus::Found{302, "Found", "HTTP/1.1 302 Found\r\n"};
const ResponseCode HttpStatus::See_Other{303, "See Other", "HTTP/1.1 303 See Other\r\n"};
const ResponseCode HttpStatus::Not_Modified{304, "Not Modified", "HTTP/1.1 304 Not Modified\r\n"};
const ResponseCode HttpStatus::Use_Proxy{305, "Use Proxy", "HTTP/1.1 305 Use Proxy\r\n"};
const ResponseCode HttpStatus::Reserved{306, "Reserved", "HTTP/1.1 306 Reserved\r\n"};
const ResponseCode HttpStatus::Temporary_Redirect{307, "Temporary Redirect", "HTTP/1.1 307 Temporary Redirect\r\n"};
const ResponseCode HttpStatus::Permanent_Redirect{308, "Permanent Redirect", "HTTP/1.1 308 Permanent Redirect\r\n"};
const ResponseCode HttpStatus::Bad_Request{400, "Bad Request", "HTTP/1.1 400 Bad Request\r\n"};
const ResponseCode HttpStatus::Unauthorized{401, "Unauthorized", "HTTP/1.1 401 Unauthorized\r\n"};
const ResponseCode HttpStatus::Payment_Required{402, "Payment Required", "HTTP/1.1 402 Payment Required\r\n"};
const ResponseCode HttpStatus::Forbidden{403, "Forbidden", "HTTP/1.1 403 Forbidden\r\n"};
const ResponseCode HttpStatus::Not_Found{404, "Not Found", "HTTP/1.1 404 Not Found\r\n"};
const ResponseCode HttpStatus::Method_Not_Allowed{405, "Method Not Allowed", "HTTP/1.1 405 Method Not Allowed\r\n"};
const ResponseCode HttpStatus::Not_Acceptable{406, "Not Acceptable", "HTTP/1.1 406 Not Acceptable\r\n"};
const ResponseCode HttpStatus::Proxy_Authentication_Required{407, "Proxy Authentication Required", "HTTP/1.1 407 Proxy Authentication Required\r\n"};
const ResponseCode HttpStatus::Request_Timeout{408, "Request Timeout", "HTTP/1.1 408 Request Timeout\r\n"};
const ResponseCode HttpStatus::Conflict{409, "Conflict", "HTTP/1.1 409 Conflict\r\n"};
const ResponseCode HttpStatus::Gone{410, "Gone", "HTTP/1.1 410 Gone\r\n"};
const ResponseCode HttpStatus::Length_Required{411, "Length Required", "HTTP/1.1 411 Length Required\r\n"};
const ResponseCode HttpStatus::Precondition_Failed{412, "Precondition Failed", "HTTP/1.1 412 Precondition Failed\r\n"};
const ResponseCode HttpStatus::Request_Entity_Too_Large{413, "Request Entity Too Large", "HTTP/1.1 413 Request Entity Too Large\r\n"};
const ResponseCode HttpStatus::Request_URI_Too_Long{414, "Request-URI Too Long", "HTTP/1.1 414 Request-URI Too Long\r\n"};
const ResponseCode HttpStatus::Unsupported_Media_Type{415, "Unsupported Media Type", "HTTP/1.1 415 Unsupported Media Type\r\n"};
const ResponseCode HttpStatus::Requested_Range_Not_Satisfiable{416, "Requested Range Not Satisfiable", "HTTP/1.1 416 Requested Range Not Satisfiable\r\n"};
const ResponseCode HttpStatus::Expectation_Failed{417, "Expectation Failed", "HTTP/1.1 417 Expectation Failed\r\n"};
const ResponseCode HttpStatus::Unprocessable_Entity{422, "Unprocessable Entity", "HTTP/1.1 422 Unprocessable Entity\r\n"};
const ResponseCode HttpStatus::Locked{423, "Locked", "HTTP/1.1 423 Locked\r\n"};
const ResponseCode HttpStatus::Failed_Dependency{424, "Failed Dependency", "HTTP/1.1 424 Failed Dependency\r\n"};
const ResponseCode HttpStatus::Upgrade_Required{426, "Upgrade Required", "HTTP/1.1 426 Upgrade Required\r\n"};
const ResponseCode HttpStatus::Precondition_Required{428, "Precondition Required", "HTTP/1.1 428 Precondition Required\r\n"};
const ResponseCode HttpStatus::Too_Many_Requests{429, "Too Many Requests", "HTTP/1.1 429 Too Many Requests\r\n"};
const ResponseCode HttpStatus::Request_Header_Fields_Too_Large{431, "Request Header Fields Too Large", "HTTP/1.1 431 Request Header Fields Too Large\r\n"};
const ResponseCode HttpStatus::Internal_Server_Error{500, "Internal Server Error", "HTTP/1.1 500 Internal Server Error\r\n"};
const ResponseCode HttpStatus::Not_Implemented{501, "Not Implemented", "HTTP/1.1 501 Not Implemented\r\n"};
const ResponseCode HttpStatus::Bad_Gateway{502, "Bad Gateway", "HTTP/1.1 502 Bad Gateway\r\n"};
const ResponseCode HttpStatus::Service_Unavailable{503, "Service Unavailable", "HTTP/1.1 503 Service Unavailable\r\n"};
const ResponseCode HttpStatus::Gateway_Timeout{504, "Gateway Timeout", "HTTP/1.1 504 Gateway Timeout\r\n"};
const ResponseCode HttpStatus::HTTP_Version_Not_Supported{505, "HTTP Version Not Supported", "HTTP/1.1 505 HTTP Version Not Supported\r\n"};
const ResponseCode HttpStatus::Variant_Also_Negotiates{506, "Variant Also Negotiates", "HTTP/1.1 506 Variant Also Negotiates\r\n"};
const ResponseCode HttpStatus::Insufficient_Storage{507, "Insufficient Storage", "HTTP/1.1 507 Insufficient Storage\r\n"};
const ResponseCode HttpStatus::Loop_Detected{508, "Loop Detected", "HTTP/1.1 508 Loop Detected\r\n"};
const ResponseCode HttpStatus::Not_Extended{510, "Not Extended", "HTTP/1.1 510 Not Extended\r\n"};
const ResponseCode HttpStatus::Network_Authentication_Required{511, "Network Authentication Required", "HTTP/1.1 511 Network Authentication Required\r\n"};
