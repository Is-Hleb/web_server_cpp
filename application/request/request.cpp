//
// Created by admin on 21.02.22.
//

#include <iostream>
#include "request.h"
#include "../utilites/strings/strings.h"

namespace core {
    request::request(std::string request_string) {
        this->request_string = std::move(request_string);
        this->parse_uri();
        this->parse_headers();
    }

    void request::parse_uri() {

        // The first items of request is Method and Uri
        std::vector<std::string> exploded = utils_strings::explode(this->request_string, ' ', 2);


        this->method = exploded[0];
        this->uri = exploded[1];

        int uri_is_get_array_id = this->uri.find('?');
        int uri_have_and_id = this->uri.find('&');

        if (uri_is_get_array_id != std::string::npos) {
            std::string temp_uri = this->uri;
            this->uri = this->uri.substr(0, uri_is_get_array_id);

            if (uri_have_and_id == std::string::npos) {
                exploded = utils_strings::explode(
                        temp_uri.substr(
                                uri_is_get_array_id + 1,
                                temp_uri.size() - uri_is_get_array_id
                        ),
                        '='
                );

                this->get_values[exploded[0]] = exploded[1];
            } else {
                std::vector<std::string> get_values_temp = utils_strings::explode(
                        temp_uri.substr(2, temp_uri.size() - 1),
                        '&'
                );
                for (std::string get_item: get_values_temp) {
                    exploded = utils_strings::explode(
                            get_item,
                            '='
                    );
                    this->get_values[exploded[0]] = exploded[1];
                }

                std::destroy(get_values_temp.begin(), get_values_temp.end());
            }
        }

    }

    void request::parse_headers() {
        std::vector<std::string> temp = utils_strings::explode(this->request_string, '\n');
        std::vector<std::string> exploded(0);

        for(auto header : temp) {
            if(header.find(':') != std::string::npos) {
                exploded = utils_strings::explode(header, ':');
                if(exploded.size() == 2) {
                    this->headers[exploded[0]] = exploded[1];
                }
            }
        }
    }

    std::string request::get_uri() {
        return this->uri;
    }

    std::string request::get_method() {
        return this->method;
    }

    std::string request::get_header(std::string name) {
        return this->headers[name];
    }
}