#include "Networking.hpp"
#include <string>
#include <iostream>

int main() {
    // TCP_Client client;
    TCP_Client client(8080, INADDR_LOOPBACK); // Connect to localhost on port 8080
    std::cout << "Client initialized." << std::endl;

    std::cout << "Connecting to server..." << std::endl;
    client.connect_to_server();
    std::cout << "Connected to server." << std::endl;

    std::cout << "Sending message to server..." << std::endl;
    client.write_to_server("Hello, Server!");

    std::cout << "Reading response from server..." << std::endl;
    std::string response = client.read_from_server();
    std::cout << "Received from server: " << response << std::endl;

    client.close_client();

    return 0;
}