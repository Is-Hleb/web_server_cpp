//
// Created by admin on 20.02.22.
//

#include "socket.h"
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sstream>

socket::socket(std::string host, std::string port) {
    this->server_settings.ai_family = AF_INET;
    this->server_settings.ai_protocol = IPPROTO_TCP;
    this->server_settings.ai_socktype = SOCK_STREAM;
    this->server_settings.ai_flags = AI_PASSIVE;

    int ex_res = getaddrinfo(
            host.c_str(),
            port.c_str(),
            &this->server_settings,
            &this->server_address_info
    );

    std::cout << "Address Info executed with status " + std::to_string(ex_res) << std::endl;

    this->server_socket = ::socket(
            this->server_address_info->ai_family,
            this->server_address_info->ai_socktype,
            this->server_address_info->ai_protocol
    );
    do {
        ex_res = ::bind(
                this->server_socket,
                this->server_address_info->ai_addr,
                (int) this->server_address_info->ai_addrlen
        );
        std::cout << "Socket bind completed with " + std::to_string(ex_res) << std::endl;
        sleep(2);
    } while(ex_res != 0);


}

bool socket::start_listen() {
    return ::listen(this->server_socket, SOMAXCONN);
}

core::request socket::start_exchange(class core::response response, int buffer_size) {
    char buffer[buffer_size];
    this->client_socket = accept(this->server_socket, nullptr, nullptr);
    int ex_res = ::recv(this->client_socket, &buffer, buffer_size, 0);
    if (ex_res == 0) {
        std::cout << "Receive executed with err " + std::to_string(ex_res) << std::endl;
        class core::request request("");
        return request;
    } else {
        buffer[buffer_size] = '\0';
        std::string response_string = response.get_completed_string();

        ex_res = ::send(this->client_socket, response_string.c_str(),
                        response_string.length(), 0);

        ::close(this->client_socket);
        std::string output(buffer, buffer_size);
        class core::request request(output);
        return request;
    }
}
