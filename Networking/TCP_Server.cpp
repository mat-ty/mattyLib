#pragma once

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

class TCP_Server
{
    private:
        int fd;
        struct sockaddr_in addr;
        


}