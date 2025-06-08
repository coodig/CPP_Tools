#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>
#include <vector>
#include <filesystem>

std::vector<std::filesystem::path> getFilesInDirectory(const std::string& directoryPath);
bool isValidDirectory(const std::string& path);

#endif