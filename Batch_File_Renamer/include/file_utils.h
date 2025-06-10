// #ifndef FILE_UTILS_H
// #define FILE_UTILS_H

// #include <string>
// #include <vector>
// #include <filesystem>

// namespace fs = std::filesystem;

// bool isValidDirectory(const std::string& path);

// std::vector<fs::directory_entry> getFilesWithExtension(const std::string& path, const std::string& extension);

// bool renameFiles(const std::vector<fs::directory_entry>&files ,const std::string& baseName, const std::string& extension);
// #endif

#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>
#include <vector>
#include <filesystem>

std::vector<std::filesystem::directory_entry> getFilesWithExtension(const std::string& path, const std::string& extension);
bool renameFiles(const std::vector<std::filesystem::directory_entry>& files, const std::string& baseName, const std::string& extension);

#endif
