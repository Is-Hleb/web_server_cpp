//
// Created by admin on 20.02.22.
//

#ifndef UNTITLED_SOCKET_H
#define UNTITLED_SOCKET_H

#include <string>
#include <netdb.h>
#include <sstream>
#include "../response/response.h"
#include "../request/request.h"

class socket {
    int client_socket = 0, server_socket = 0;
    std::string headers, body;
    struct addrinfo* server_address_info = NULL;
    struct addrinfo server_settings{};

public:
    explicit socket(std::string host, std::string port = "8080");
    bool start_listen();
    core::request start_exchange(class core::response response, int buffer_size = 2048);
};


#endif //UNTITLED_SOCKET_H
