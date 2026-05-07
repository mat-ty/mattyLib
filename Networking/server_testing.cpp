#include "Networking.hpp"


int main() {
    TCP_Server server(8080, INADDR_ANY, 1);
    server.start();


    return 0;
}