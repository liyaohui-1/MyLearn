cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)  

set(EPOLL_CLIENT epoll_client)
set(EPOLL_SERVER epoll_server)

add_executable(${EPOLL_CLIENT} epoll_client.cpp)
add_executable(${EPOLL_SERVER} epoll_server.cpp)