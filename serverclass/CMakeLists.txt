cmake_minimum_required(VERSION 3.15)
project(serverclass)

set(CMAKE_CXX_STANDARD 14)

add_executable(serverclass ipv4/serveripv4.cpp ipv4/serveripv4.h main.cpp ipv6/serveripv6.cpp ipv6/serveripv6.h udp/serverudp.cpp udp/serverudp.h)