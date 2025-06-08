#include "renamer.h"
#include "../../common/logger.h"
#include <iostream>
#include <filesystem>
#include <sstream>
#include <iomanip>
#include <vector>

namespace fs = std::filesystem;

std::vector<fs::path> getFilesInDirectory(const std::string& directory) {
std::vector<fs::path> files;
if (!fs::exists(directory) || !fs::is_directory(directory)) {
logError("Invalid directory: " + directory);
return files;
}

for (const auto& entry : fs::directory_iterator(directory)) {
    if (fs::is_regular_file(entry.path())) {
        files.push_back(entry.path());
    }
}

return files;

}

void renameFilesWithPattern(const std::vector<fs::path>& files, const std::string& pattern, const std::string& mode) {
for (const auto& file : files) {
std::string originalName = file.stem().string();
std::string extension = file.extension().string();
fs::path newPath;
    if (mode == "prefix") {
        newPath = file.parent_path() / (pattern + "_" + originalName + extension);
    } else if (mode == "suffix") {
        newPath = file.parent_path() / (originalName + "_" + pattern + extension);
    } else {
        logError("Invalid mode: Use 'prefix' or 'suffix'");
        return;
    }

    try {
        fs::rename(file, newPath);
        logSuccess("Renamed: " + file.filename().string() + " -> " + newPath.filename().string());
    } catch (const std::exception& e) {
        logError("Failed to rename " + file.filename().string() + ": " + e.what());
    }
}

}

void renameFilesSequentially(const std::vector<fs::path>& files, const std::string& baseName) {
int width = std::to_string(files.size()).length(); // padding width

for (size_t i = 0; i < files.size(); ++i) {
    std::ostringstream newName;
    newName << baseName << std::setfill('0') << std::setw(width) << (i + 1) << files[i].extension().string();

    fs::path newPath = files[i].parent_path() / newName.str();

    try {
        fs::rename(files[i], newPath);
        logSuccess("Renamed: " + files[i].filename().string() + " -> " + newPath.filename().string());
    } catch (const std::exception& e) {
        logError("Failed to rename " + files[i].filename().string() + ": " + e.what());
    }
}
}