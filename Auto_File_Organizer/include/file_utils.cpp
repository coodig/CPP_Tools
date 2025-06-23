#include "file_utils.h"
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

bool createFolderIfNotExists(const std::string& path) {
    if (!fs::exists(path)) {
        return fs::create_directories(path);
    }
    return true;
}

std::string getExtension(const std::string& filename) {
    fs::path filePath(filename);
    return filePath.extension().string();
}

bool moveFile(const std::string& from, const std::string& to) {
    try {
        fs::rename(from, to);
        return true;
    } catch (...) {
        return false;
    }
}
