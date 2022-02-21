//
// Created by admin on 21.02.22.
//

#include <string>
#include <fstream>
#include <iostream>
#include <utility>

namespace utils_files {
    std::string get_path(std::string path) {;
        return std::filesystem::current_path().string() + "/../" + path;
    }

    std::string file_to_string(std::string file_path) {
        std::ifstream fin(get_path(file_path));
        std::string output = "", buffer;

        while(std::getline(fin, buffer)) {
            output += buffer;
        }

        fin.close();
        return output;
    }

    std::string get_file_extension(std::string path) {
        std::string ext = "";
        size_t index = path.size() - 1;
        while(path[index] != '.') {
            ext = path[index--] + ext;
        }
        return ext;
    }
}