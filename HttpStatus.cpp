#include "HttpStatus.h"

const ResponseCode HttpStatus::Continue{100, "Continue", "HTTP/1.1 100 Continue"};
const ResponseCode HttpStatus::Switching_Protocols{101, "Switching Protocols", "HTTP/1.1 101 Switching Protocols"};
const ResponseCode HttpStatus::Processing{102, "Processing", "HTTP/1.1 102 Processing"};
const ResponseCode HttpStatus::OK{200, "OK", "HTTP/1.1 200 OK"};
const ResponseCode HttpStatus::Created{201, "Created", "HTTP/1.1 201 Created"};
const ResponseCode HttpStatus::Accepted{202, "Accepted", "HTTP/1.1 202 Accepted"};
const ResponseCode HttpStatus::Non_Authoritative_Information{203, "Non-Authoritative Information", "HTTP/1.1 203 Non-Authoritative Information"};
const ResponseCode HttpStatus::No_Content{204, "No Content", "HTTP/1.1 204 No Content"};
const ResponseCode HttpStatus::Reset_Content{205, "Reset Content", "HTTP/1.1 205 Reset Content"};
const ResponseCode HttpStatus::Partial_Content{206, "Partial Content", "HTTP/1.1 206 Partial Content"};
const ResponseCode HttpStatus::Multi_Status{207, "Multi-Status", "HTTP/1.1 207 Multi-Status"};
const ResponseCode HttpStatus::Already_Reported{208, "Already Reported", "HTTP/1.1 208 Already Reported"};
const ResponseCode HttpStatus::IM_Used{226, "IM Used", "HTTP/1.1 226 IM Used"};
const ResponseCode HttpStatus::Multiple_Choices{300, "Multiple Choices", "HTTP/1.1 300 Multiple Choices"};
const ResponseCode HttpStatus::Moved_Permanently{301, "Moved Permanently", "HTTP/1.1 301 Moved Permanently"};
const ResponseCode HttpStatus::Found{302, "Found", "HTTP/1.1 302 Found"};
const ResponseCode HttpStatus::See_Other{303, "See Other", "HTTP/1.1 303 See Other"};
const ResponseCode HttpStatus::Not_Modified{304, "Not Modified", "HTTP/1.1 304 Not Modified"};
const ResponseCode HttpStatus::Use_Proxy{305, "Use Proxy", "HTTP/1.1 305 Use Proxy"};
const ResponseCode HttpStatus::Reserved{306, "Reserved", "HTTP/1.1 306 Reserved"};
const ResponseCode HttpStatus::Temporary_Redirect{307, "Temporary Redirect", "HTTP/1.1 307 Temporary Redirect"};
const ResponseCode HttpStatus::Permanent_Redirect{308, "Permanent Redirect", "HTTP/1.1 308 Permanent Redirect"};
const ResponseCode HttpStatus::Bad_Request{400, "Bad Request", "HTTP/1.1 400 Bad Request"};
const ResponseCode HttpStatus::Unauthorized{401, "Unauthorized", "HTTP/1.1 401 Unauthorized"};
const ResponseCode HttpStatus::Payment_Required{402, "Payment Required", "HTTP/1.1 402 Payment Required"};
const ResponseCode HttpStatus::Forbidden{403, "Forbidden", "HTTP/1.1 403 Forbidden"};
const ResponseCode HttpStatus::Not_Found{404, "Not Found", "HTTP/1.1 404 Not Found"};
const ResponseCode HttpStatus::Method_Not_Allowed{405, "Method Not Allowed", "HTTP/1.1 405 Method Not Allowed"};
const ResponseCode HttpStatus::Not_Acceptable{406, "Not Acceptable", "HTTP/1.1 406 Not Acceptable"};
const ResponseCode HttpStatus::Proxy_Authentication_Required{407, "Proxy Authentication Required", "HTTP/1.1 407 Proxy Authentication Required"};
const ResponseCode HttpStatus::Request_Timeout{408, "Request Timeout", "HTTP/1.1 408 Request Timeout"};
const ResponseCode HttpStatus::Conflict{409, "Conflict", "HTTP/1.1 409 Conflict"};
const ResponseCode HttpStatus::Gone{410, "Gone", "HTTP/1.1 410 Gone"};
const ResponseCode HttpStatus::Length_Required{411, "Length Required", "HTTP/1.1 411 Length Required"};
const ResponseCode HttpStatus::Precondition_Failed{412, "Precondition Failed", "HTTP/1.1 412 Precondition Failed"};
const ResponseCode HttpStatus::Request_Entity_Too_Large{413, "Request Entity Too Large", "HTTP/1.1 413 Request Entity Too Large"};
const ResponseCode HttpStatus::Request_URI_Too_Long{414, "Request-URI Too Long", "HTTP/1.1 414 Request-URI Too Long"};
const ResponseCode HttpStatus::Unsupported_Media_Type{415, "Unsupported Media Type", "HTTP/1.1 415 Unsupported Media Type"};
const ResponseCode HttpStatus::Requested_Range_Not_Satisfiable{416, "Requested Range Not Satisfiable", "HTTP/1.1 416 Requested Range Not Satisfiable"};
const ResponseCode HttpStatus::Expectation_Failed{417, "Expectation Failed", "HTTP/1.1 417 Expectation Failed"};
const ResponseCode HttpStatus::Unprocessable_Entity{422, "Unprocessable Entity", "HTTP/1.1 422 Unprocessable Entity"};
const ResponseCode HttpStatus::Locked{423, "Locked", "HTTP/1.1 423 Locked"};
const ResponseCode HttpStatus::Failed_Dependency{424, "Failed Dependency", "HTTP/1.1 424 Failed Dependency"};
const ResponseCode HttpStatus::Upgrade_Required{426, "Upgrade Required", "HTTP/1.1 426 Upgrade Required"};
const ResponseCode HttpStatus::Precondition_Required{428, "Precondition Required", "HTTP/1.1 428 Precondition Required"};
const ResponseCode HttpStatus::Too_Many_Requests{429, "Too Many Requests", "HTTP/1.1 429 Too Many Requests"};
const ResponseCode HttpStatus::Request_Header_Fields_Too_Large{431, "Request Header Fields Too Large", "HTTP/1.1 431 Request Header Fields Too Large"};
const ResponseCode HttpStatus::Internal_Server_Error{500, "Internal Server Error", "HTTP/1.1 500 Internal Server Error"};
const ResponseCode HttpStatus::Not_Implemented{501, "Not Implemented", "HTTP/1.1 501 Not Implemented"};
const ResponseCode HttpStatus::Bad_Gateway{502, "Bad Gateway", "HTTP/1.1 502 Bad Gateway"};
const ResponseCode HttpStatus::Service_Unavailable{503, "Service Unavailable", "HTTP/1.1 503 Service Unavailable"};
const ResponseCode HttpStatus::Gateway_Timeout{504, "Gateway Timeout", "HTTP/1.1 504 Gateway Timeout"};
const ResponseCode HttpStatus::HTTP_Version_Not_Supported{505, "HTTP Version Not Supported", "HTTP/1.1 505 HTTP Version Not Supported"};
const ResponseCode HttpStatus::Variant_Also_Negotiates{506, "Variant Also Negotiates", "HTTP/1.1 506 Variant Also Negotiates"};
const ResponseCode HttpStatus::Insufficient_Storage{507, "Insufficient Storage", "HTTP/1.1 507 Insufficient Storage"};
const ResponseCode HttpStatus::Loop_Detected{508, "Loop Detected", "HTTP/1.1 508 Loop Detected"};
const ResponseCode HttpStatus::Not_Extended{510, "Not Extended", "HTTP/1.1 510 Not Extended"};
const ResponseCode HttpStatus::Network_Authentication_Required{511, "Network Authentication Required", "HTTP/1.1 511 Network Authentication Required"};
const std::map<int, ResponseCode> statusMap = {
  {100, HttpStatus::Continue},
  {101, HttpStatus::Switching_Protocols},
  {102, HttpStatus::Processing},
  {200, HttpStatus::OK},
  {201, HttpStatus::Created},
  {202, HttpStatus::Accepted},
  {203, HttpStatus::Non_Authoritative_Information},
  {204, HttpStatus::No_Content},
  {205, HttpStatus::Reset_Content},
  {206, HttpStatus::Partial_Content},
  {207, HttpStatus::Multi_Status},
  {208, HttpStatus::Already_Reported},
  {226, HttpStatus::IM_Used},
  {300, HttpStatus::Multiple_Choices},
  {301, HttpStatus::Moved_Permanently},
  {302, HttpStatus::Found},
  {303, HttpStatus::See_Other},
  {304, HttpStatus::Not_Modified},
  {305, HttpStatus::Use_Proxy},
  {306, HttpStatus::Reserved},
  {307, HttpStatus::Temporary_Redirect},
  {308, HttpStatus::Permanent_Redirect},
  {400, HttpStatus::Bad_Request},
  {401, HttpStatus::Unauthorized},
  {402, HttpStatus::Payment_Required},
  {403, HttpStatus::Forbidden},
  {404, HttpStatus::Not_Found},
  {405, HttpStatus::Method_Not_Allowed},
  {406, HttpStatus::Not_Acceptable},
  {407, HttpStatus::Proxy_Authentication_Required},
  {408, HttpStatus::Request_Timeout},
  {409, HttpStatus::Conflict},
  {410, HttpStatus::Gone},
  {411, HttpStatus::Length_Required},
  {412, HttpStatus::Precondition_Failed},
  {413, HttpStatus::Request_Entity_Too_Large},
  {414, HttpStatus::Request_URI_Too_Long},
  {415, HttpStatus::Unsupported_Media_Type},
  {416, HttpStatus::Requested_Range_Not_Satisfiable},
  {417, HttpStatus::Expectation_Failed},
  {422, HttpStatus::Unprocessable_Entity},
  {423, HttpStatus::Locked},
  {424, HttpStatus::Failed_Dependency},
  {426, HttpStatus::Upgrade_Required},
  {428, HttpStatus::Precondition_Required},
  {429, HttpStatus::Too_Many_Requests},
  {431, HttpStatus::Request_Header_Fields_Too_Large},
  {500, HttpStatus::Internal_Server_Error},
  {501, HttpStatus::Not_Implemented},
  {502, HttpStatus::Bad_Gateway},
  {503, HttpStatus::Service_Unavailable},
  {504, HttpStatus::Gateway_Timeout},
  {505, HttpStatus::HTTP_Version_Not_Supported},
  {506, HttpStatus::Variant_Also_Negotiates},
  {507, HttpStatus::Insufficient_Storage},
  {508, HttpStatus::Loop_Detected},
  {510, HttpStatus::Not_Extended},
  {511, HttpStatus::Network_Authentication_Required}
};
