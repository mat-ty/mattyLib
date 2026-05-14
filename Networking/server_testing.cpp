#include "./Networking.hpp"


int main() {
    TCP_Server server(8080, INADDR_ANY, 1);
    std::cout << "Server initialized." << std::endl;
    
    server.start();


    return 0;
}