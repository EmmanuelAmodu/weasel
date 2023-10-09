#include <iostream>
#include <string>
#include <boost/asio.hpp>

namespace asio = boost::asio;
using tcp = boost::asio::ip::tcp;

// Callback function to read the response received from the server
void handle_read(const boost::system::error_code &error, size_t bytes_transferred, std::string &response)
{
    if (!error)
    {
        response.resize(bytes_transferred);
        std::cout << "Response Payload :" << std::endl
                  << response
                  << std::endl;
    }
    else
    {
        std::cerr << "Error reading response: " << error.message() << std::endl;
    }
}

int main()
{
    // XML payload to be sent to the HTTP endpoint
    std::string xmlPayload = R"XML(<?xml version="1.0" encoding="UTF-8"?>
<ns2:paymentinstructionrequest xmlns:ns2="http://www.ericsson.com/em/emm/settlement/v2_0">
    <transactiontimestamp>
        <timestamp>2022-07-31T13:41:07</timestamp>
    </transactiontimestamp>
    <amount>
        <amount>777.0</amount>
        <currency>UG</currency>
    </amount>
    <paymentinstructionid>7571113</paymentinstructionid>
    <receiverbankcode>00063</receiverbankcode>
    <receiveraccountnumber>1029326598</receiveraccountnumber>
    <receiverfirstname>Jagadeesh</receiverfirstname>
    <receiversurname>Pilla</receiversurname>
    <message>Jagadeesh MTN Escrow Test</message>
</ns2:paymentinstructionrequest>
)XML";

    // HTTP endpoint URL
    std::string host = "m3.extio.io"; // Replace with actual Hostname and Port
    std::string path = "/escrow";

    // TCP resolver and socket
    asio::io_context io_context;
    tcp::resolver resolver(io_context);
    tcp::socket socket(io_context);

    // Connect to the server
    tcp::resolver::results_type endpoints = resolver.resolve(host, "http");
    asio::connect(socket, endpoints);

    // Send the HTTP request
    std::string request = "POST " + path + " HTTP/1.1\r\n"
                                           "Host: " +
                          host + "\r\n"
                                 "Content-Length: " +
                          std::to_string(xmlPayload.length()) + "\r\n"
                                                                "Content-Type: text/xml\r\n"
                                                                "Connection: close\r\n"
                                                                "\r\n" +
                          xmlPayload;
    asio::write(socket, asio::buffer(request));

    // Read the response asynchronously
    std::string response;
    asio::async_read(socket, asio::dynamic_buffer(response), std::bind(&handle_read, std::placeholders::_1, std::placeholders::_2, std::ref(response)));

    // Run the asio event loop
    io_context.run();

    return 0;
}
