//
// Created by admin on 21.02.22.
//

#include <sstream>
#include <utility>
#include "response.h"
#include "../utilites/files/files.h"

using namespace core;

void response::set_body_from_file(const std::string& path_from_root, const std::string& file_extension) {
    this->set_default_headers();
    this->body = utils_files::file_to_string("server/" + path_from_root);
    this->headers.push_back("Content-Type: text/" + file_extension + "; charset=utf-8");
    this->headers.push_back("Content-Length: " + std::to_string(this->body.length()));
}

void response::set_body_from_string(std::string body, const std::string& content_type) {
    this->set_default_headers();

    this->headers.push_back("Content-Type: " + content_type + "; charset=utf-8");
    this->headers.push_back("Content-Length: " + std::to_string(body.length()));

    this->body = std::move(body);
}

void response::set_default_headers() {
    this->headers = {
            "HTTP/1.1 200 OK",
            "Version: HTTP/1.1",
    };

}

std::string response::get_completed_string() {
    std::string response;
    for(size_t index = 0; index < this->headers.size(); index++) {
        response += this->headers[index] + "\r\n";
    }
    response += "\r\n\r\n";
    response += this->body;
    return response;
}

