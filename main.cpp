// #include "./weasel/Server.h"
// #include "./weasel/Router.h"
// #include "./weasel/HttpStatus.h"
// #include "./weasel/HttpMethod.h"
// #include "./weasel/JSONParser.h"

// int main()
// {
//   Router *router = new Router();
//   router
//       ->addRoute(
//           HttpMethod::GET,
//           "/",
//           [](Request *request) -> Response *
//           {
//             return Response::make("THIS IS THE ROOT PATH GET METHOD");
//           })
//       ->addRoute(
//           HttpMethod::POST,
//           "/",
//           [](Request *request) -> Response *
//           {
//             return Response::make("THIS IS THE ROOT PATH POST METHOD");
//           });

//   Server server{router};
//   server.startServer();
//   delete router;
//   return 0;
// }
#include <string>
#include <iostream>
#include <json/json.h>

int main() {
    // JSON-formatted string
    // std::string value1 = "                 {\"glossary       }          \": \"string value          \", \"boolean\": true, \"number\": 123, \"array\": [1, 2, 3], \"object\": {\"key\": \"value\"} }";
    std::string jsonString = R"({"key": "value", "number": 42, "nested": {"inner": "data"}})";

    // Create a Json::Value object
    Json::Value root;

    // Create a Json::Reader object
    Json::Reader reader;

    // Parse the JSON string
    bool parsingSuccessful = reader.parse(jsonString, root);

    // Check if parsing was successful
    if (parsingSuccessful) {
        // Access values in the Json::Value object
        std::string key = root["key"].asString();
        int number = root["number"].asInt();
        std::string inner = root["nested"]["inner"].asString();

        // Print the values
        std::cout << "Key: " << key << std::endl;
        std::cout << "Number: " << number << std::endl;
        std::cout << "Inner: " << inner << std::endl;
    } else {
        // Handle parsing error
        std::cerr << "Failed to parse JSON string" << std::endl;
    }

    return 0;
}