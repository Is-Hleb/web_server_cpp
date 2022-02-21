//
// Created by admin on 21.02.22.
//
#include <iostream>
#include "strings.h"
namespace utils_strings {
    std::vector<std::string> explode(const std::string& string, char sep, int items_count) {
        std::string buf = string;
        std::string tmp;
        std::vector<std::string> exploded(0);

        bool is_inf = items_count == -1;
        int items_count_buf = items_count;
        buf += sep;
        for(size_t i = 0; i < buf.size(); i++) {
            if(buf[i] != sep) {
                tmp += buf[i];
            } else {
                exploded.push_back(tmp);
                tmp = "";
                if(!is_inf && --items_count_buf <= 0) {
                    break;
                }
            }
        }

        while(!is_inf && exploded.size() < items_count) {
            exploded.emplace_back("");
        }

        std::destroy(tmp.begin(), tmp.end());
        std::destroy(buf.begin(), buf.end());
        return exploded;
    }
}
