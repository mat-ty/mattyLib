

#include "BindingSocket.hpp"

//Constructor
mg::BindingSocket::BindingSocket(int domain, int service, int protocol, int port,
        u_long interface) : SimpleSocket(domain, service, protocol, port, interface)
{
    set_connection(connect_to_network(get_sock(), get_address()));
    test_connection(get_connection());
}

// Implimentation of inheirited virtual function 
int mg::BindingSocket::connect_to_network(int sock, struct sockaddr_in addr)
{
    return bind(sock, (struct sockaddr *)&addr, sizeof(addr));
}