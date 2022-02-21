//
// Created by admin on 21.02.22.
//

#ifndef UNTITLED_RESPONSE_H
#define UNTITLED_RESPONSE_H

#include <string>
#include <vector>

#define JSON_RESPONSE 1;
#define PLAIN_RESPONSE 2;

namespace core {
    class response {
        std::string body = "";
        std::vector<std::string> headers;

    public:
        void set_body_from_file(const std::string& path_from_root, const std::string& file_extension = "html");

        void set_body_from_string(std::string body, const std::string& content_type = "text/html");
        void set_default_headers();

        void add_custom_headers(std::vector<std::string> headers);

        std::string get_completed_string();
    };
}

#endif //UNTITLED_RESPONSE_H
