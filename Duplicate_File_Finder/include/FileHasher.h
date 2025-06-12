#pragma once
#include <string>

class FileHasher{
    public:
    static std::string hashFile(const std::string& filePath);
};