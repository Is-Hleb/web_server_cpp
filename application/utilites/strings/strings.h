//
// Created by admin on 21.02.22.
//

#ifndef UNTITLED_STRINGS_H
#define UNTITLED_STRINGS_H

#endif //UNTITLED_STRINGS_H

#include <string>
#include <vector>

#define STRING_EXPLODE_ALL -1

namespace utils_strings {
    std::vector<std::string> explode(const std::string& string, char sep = ' ', int items_count = STRING_EXPLODE_ALL);
}