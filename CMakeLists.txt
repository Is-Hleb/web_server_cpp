cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 23)

add_executable(untitled main.cpp application/socket/socket.cpp application/socket/socket.h application/utilites/files/files.h application/utilites/files/files.cpp application/response/response.cpp application/response/response.h  application/request/request.cpp application/request/request.h application/utilites/strings/strings.cpp application/utilites/strings/strings.h)
