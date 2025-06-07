#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>

bool createFolderIfNotExists(const std::string& path);
std::string getExtension(const std::string& filename);
bool moveFile(const std::string& from, const std::string& to);

#endif
