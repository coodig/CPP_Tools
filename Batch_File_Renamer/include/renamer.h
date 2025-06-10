// #ifndef RENAMER_H
// #define RENAMER_H

// #include <string>

// void addPrefix(const std::string& folderPath, const std::string& prefix);
// void addSuffix(const std::string& folderPath, const std::string& suffix);
// void replaceSubstring(const std::string& folderPath, const std::string& from, const std::string& to);
// void renameNumbered(const std::string& folderPath);
// void renameUppercase(const std::string& folderPath);
// void renameLowercase(const std::string& folderPath);

// #endif

#ifndef RENAMER_H
#define RENAMER_H

#include <string>

void batchRenameFiles(const std::string& directoryPath, const std::string& extension, const std::string& newBaseName);

#endif
