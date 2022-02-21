#include <iostream>
#include <fstream>
#include "application/socket/socket.h"
#include "application/utilites/files/files.h"

[[noreturn]] void loop(class socket sock);

void init() {
    class socket sock("localhost", "8080");
    sock.start_listen();

    loop(sock);

}

[[noreturn]] void loop(class socket sock) {

    std::string file_path;
    core::response response;
    while (1) {
        response.set_body_from_file(file_path, utils_files::get_file_extension(file_path));
        core::request request = sock.start_exchange(response);

        std::cout << file_path << std::endl;

        std::string url = request.get_uri();
        std::cout << request.get_header("Accept");

        if(url == "/") {
            file_path = "public/index.html";
        } else {
            file_path = "public" + url;
        }


        // std::cout << sock.start_exchange(response) << std::endl;
    }
}

int main() {
    init();
    return 0;
}
