

#include "ConnectingSocket.hpp"


mg::ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port,
        u_long interface) : SimpleSocket(domain, service, protocol, port, interface)
{
    set_connection(connect_to_network(get_sock(), get_address()));
    test_connection(get_connection());
}

int mg::ConnectingSocket::connect_to_network(int sock, struct sockaddr_in addr)
{
    return connect(sock, (struct sockaddr *)&addr, sizeof(addr));
}