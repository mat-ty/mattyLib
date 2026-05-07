#include "TCP_Listener.hpp"

TCP_Listener::TCP_Listener() : TCP_Socket(), queue_size(0) {}

TCP_Listener::TCP_Listener(int port, int saddr, int qsize) 
: TCP_Socket(htons(port), htonl(saddr)), queue_size(qsize) {}

TCP_Listener::~TCP_Listener() {
    close_listener();
}

const int TCP_Listener::get_queue_size(){
    return this->queue_size;
}

int TCP_Listener::accept_connection()
{
    struct sockaddr_in client_addr{};
    socklen_t len = sizeof(client_addr);
    
    int client_fd = accept(get_fd(), (struct sockaddr *)&client_addr, &len);
    if (client_fd < 0)
    {
        die("accept() failed");
    }
    return client_fd;
}

// Start the listener
int TCP_Listener::start(){

    int val = 1;
    setsockopt(get_fd(), SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));

    if(bind(get_fd(), (const struct sockaddr *)&this->get_addr(), sizeof(this->get_addr()))==-1){
        die("Bind failed");
    }
    
    if(listen(this->get_fd(), this->get_queue_size())==-1){
        die("Listen failed");
    }
    
    return this->get_fd();
}

// Close the listener
void TCP_Listener::close_listener(){
    close_socket();
}