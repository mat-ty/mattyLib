#pragma once

#include <stdio.h>
#include "SimpleSocket.hpp"

namespace mg
{
    
    class BindingSocket: public SimpleSocket
    {
    private:
        /* data */
    public:

        BindingSocket(int domain, int service, int protocol, int port,
        u_long interface);

        int connect_to_network(int sock, struct sockaddr_in addr);
    };
    

} // namespace mg
