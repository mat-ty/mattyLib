cmake_minimum_required(VERSION 3.15)
project(Networking)

set(CMAKE_CXX_STANDARD 17)

# All your library source files
add_library(networking
    Sockets/TCP_Socket.cpp
    Sockets/TCP_Connection.cpp
    Sockets/TCP_Listener.cpp
    Nodes/TCP_Client.cpp
    Nodes/TCP_Server.cpp
)

target_include_directories(networking PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Sockets
    ${CMAKE_CURRENT_SOURCE_DIR}/Nodes
)

# Server test executable
add_executable(server_test server_testing.cpp)
target_link_libraries(server_test PRIVATE networking)

# Client test executable
add_executable(client_test client_testing.cpp)
target_link_libraries(client_test PRIVATE networking)