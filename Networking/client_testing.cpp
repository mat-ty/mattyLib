#include "Networking.hpp"
#include <string>
#include <iostream>
/**
 * takes argument from command line for message text to send to server, defaults to "Hello, Server!" if no argument is provided
 */
int main(int argc, char *argv[]) {
    // TCP_Client client;
    TCP_Client client(8080, INADDR_LOOPBACK); // Connect to localhost on port 8080
    std::cout << "Client initialized." << std::endl;

    std::cout << "Connecting to server..." << std::endl;
    client.connect_to_server();
    std::cout << "Connected to server." << std::endl;

    std::cout << "Sending message to server..." << std::endl;
    //get all subsiquent arguments from argv and concatenate them into a single message
    std::string message = (argc > 1) ? std::string(argv[1]) : "Hello, Server!";
    for (int i = 2; i < argc; i++) {
        message += " " + std::string(argv[i]);
    }
    client.write_to_server(message);
    std::cout << "Reading response from server..." << std::endl;
    std::string response = client.read_from_server();
    std::cout << "Received from server: " << response << std::endl;

    client.close_client();

    return 0;
}