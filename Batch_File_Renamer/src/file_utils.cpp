#include "file_utils.h"
#include <filesystem>

namespace fs = std::filesystem;

bool isValidDirectory(const std::string& path) {
return fs::exists(path) && fs::is_directory(path);
}

std::vectorfs::path getFilesInDirectory(const std::string& directoryPath) {
std::vectorfs::path files;

if (!isValidDirectory(directoryPath))
    return files;

for (const auto& entry : fs::directory_iterator(directoryPath)) {
    if (fs::is_regular_file(entry.status())) {
        files.push_back(entry.path());
    }
}

return files;
}
