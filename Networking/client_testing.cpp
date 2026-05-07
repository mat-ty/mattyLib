#include "Networking.hpp"
#include <string>
#include <iostream>

int main() {
    TCP_Client client;
    client = TCP_Client(8080, INADDR_ANY);
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