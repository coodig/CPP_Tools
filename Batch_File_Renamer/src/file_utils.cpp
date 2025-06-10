// #include "file_utils.h"
// #include <filesystem>
// #include <iostream>
// #include <sstream>

// namespace fs = std::filesystem;

// bool isValidDirectory(const std::string& path) {
// return fs::exists(path) && fs::is_directory(path);
// }

// std::vector<fs::directory_entry> getFilesWithExtension(const std::string& path, const std::string& extension) {
// std::vector<fs::directory_entry> matchingFiles;

// // if (!isValidDirectory(directoryPath))
// //     return files;

// for (const auto& entry : fs::directory_iterator(path)) {
//     if (entry.is_regular_file()) {
//         if(entry.path().extension() == extension){
//             matchingFiles.push_back(entry);
//         }
//     }
// }
// return matchingFiles;
// }

// bool renameFiles(const std::vector<fs::directory_entry>& files, const std::string& baseName, const std::string& extension) {
//     int count = 1;
//     for (const auto& file : files) {
//         std::ostringstream newFilename;
//         newFilename << baseName << "_" << count << extension;

//         fs::path newPath = file.path().parent_path() / newFilename.str();

//         try {
//             fs::rename(file.path(), newPath);
//             ++count;
//         } catch (const std::exception& e) {
//             std::cerr << "Failed to rename: " << file.path() << " -> " << e.what() << std::endl;
//             return false;
//         }
//     }

//     return true;
// }

#include "file_utils.h"
#include <filesystem>
#include <iostream>
#include <sstream>
#include <vector>

namespace fs = std::filesystem;

std::vector<fs::directory_entry> getFilesWithExtension(const std::string& path, const std::string& extension) {
    std::vector<fs::directory_entry> matchingFiles;

    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file() && entry.path().extension() == extension) {
            matchingFiles.push_back(entry);
        }
    }

    return matchingFiles;
}

bool renameFiles(const std::vector<fs::directory_entry>& files, const std::string& baseName, const std::string& extension) {
    int count = 1;
    for (const auto& file : files) {
        std::ostringstream newFilename;
        newFilename << baseName << "_" << count << extension;

        fs::path newPath = file.path().parent_path() / newFilename.str();

        try {
            fs::rename(file.path(), newPath);
            ++count;
        } catch (const std::exception& e) {
            std::cerr << "Failed to rename: " << file.path() << " -> " << e.what() << std::endl;
            return false;
        }
    }

    return true;
}
