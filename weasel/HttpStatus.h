#include <string>
#include <unordered_map>

#pragma once

struct ResponseCode {
  int code;
  std::string message;
  std::string signature;
};

class HttpStatus
{
  public:
    static const ResponseCode Continue;
    static const ResponseCode Switching_Protocols;
    static const ResponseCode Processing;
    static const ResponseCode OK;
    static const ResponseCode Created;
    static const ResponseCode Accepted;
    static const ResponseCode Non_Authoritative_Information;
    static const ResponseCode No_Content;
    static const ResponseCode Reset_Content;
    static const ResponseCode Partial_Content;
    static const ResponseCode Multi_Status;
    static const ResponseCode Already_Reported;
    static const ResponseCode IM_Used;
    static const ResponseCode Multiple_Choices;
    static const ResponseCode Moved_Permanently;
    static const ResponseCode Found;
    static const ResponseCode See_Other;
    static const ResponseCode Not_Modified;
    static const ResponseCode Use_Proxy;
    static const ResponseCode Reserved;
    static const ResponseCode Temporary_Redirect;
    static const ResponseCode Permanent_Redirect;
    static const ResponseCode Bad_Request;
    static const ResponseCode Unauthorized;
    static const ResponseCode Payment_Required;
    static const ResponseCode Forbidden;
    static const ResponseCode Not_Found;
    static const ResponseCode Method_Not_Allowed;
    static const ResponseCode Not_Acceptable;
    static const ResponseCode Proxy_Authentication_Required;
    static const ResponseCode Request_Timeout;
    static const ResponseCode Conflict;
    static const ResponseCode Gone;
    static const ResponseCode Length_Required;
    static const ResponseCode Precondition_Failed;
    static const ResponseCode Request_Entity_Too_Large;
    static const ResponseCode Request_URI_Too_Long;
    static const ResponseCode Unsupported_Media_Type;
    static const ResponseCode Requested_Range_Not_Satisfiable;
    static const ResponseCode Expectation_Failed;
    static const ResponseCode Unprocessable_Entity;
    static const ResponseCode Locked;
    static const ResponseCode Failed_Dependency;
    static const ResponseCode Upgrade_Required;
    static const ResponseCode Precondition_Required;
    static const ResponseCode Too_Many_Requests;
    static const ResponseCode Request_Header_Fields_Too_Large;
    static const ResponseCode Internal_Server_Error;
    static const ResponseCode Not_Implemented;
    static const ResponseCode Bad_Gateway;
    static const ResponseCode Service_Unavailable;
    static const ResponseCode Gateway_Timeout;
    static const ResponseCode HTTP_Version_Not_Supported;
    static const ResponseCode Variant_Also_Negotiates;
    static const ResponseCode Insufficient_Storage;
    static const ResponseCode Loop_Detected;
    static const ResponseCode Not_Extended;
    static const ResponseCode Network_Authentication_Required;
    static const std::unordered_map<int, ResponseCode> statusMap;
};
