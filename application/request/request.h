//
// Created by admin on 21.02.22.
//

#ifndef UNTITLED_REQUEST_H
#define UNTITLED_REQUEST_H

#define GET_METHOD 1;
#define POST_METHOD 2;

#include <string>
#include <map>

namespace core {
    class request {
        std::string method;
        std::string request_string;
        std::string uri;
        std::map<std::string, std::string> headers;
        std::map<std::string, std::string> get_values;

        void parse_uri();
        void parse_headers();
    public:
        explicit request(std::string request_string);
        std::string get_uri();
        std::string get_method();
        std::string get_header(std::string name);
    };

}
#endif //UNTITLED_REQUEST_H
