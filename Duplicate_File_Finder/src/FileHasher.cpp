#include "../include/FileHasher.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>

std::string FileHasher::hashFile(const std::string& filePath){
    std::ifstream file(filePath, std::ios::binary);
    if(!file) return "";

    std::ostringstream buffer;
    buffer<<file.rdbuf();

    std::string content = buffer.str();

    std::hash<std::string> hasher;

    return std::to_string(hasher(content));
}
