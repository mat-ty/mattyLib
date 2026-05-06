#include "TCP_Listener.hpp"

TCP_Listener::TCP_Listener() : TCP_Socket(), queue_size(1) {}

TCP_Listener::TCP_Listener(int port, int saddr, int qsize) 
: TCP_Socket(port, saddr), queue_size(qsize) {}

TCP_Listener::~TCP_Listener() {
    close_listener();
}

int TCP_Listener::get_queue_size(){
    return this->queue_size;
}

// Start the listener
int TCP_Listener::start(){
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