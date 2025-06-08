#include "renamer.h"
#include <filesystem>
#include <iostream>
#include <algorithm>
#include <cctype>

namespace fs = std::filesystem;

// Add prefix to all files
void addPrefix(const std::string& folderPath, const std::string& prefix) {
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            std::string oldName = entry.path().filename().string();
            std::string newName = prefix + oldName;
            fs::rename(entry.path(), entry.path().parent_path() / newName);
            std::cout << "Renamed: " << oldName << " -> " << newName << "\n";
        }
    }
}

// Add suffix before extension
void addSuffix(const std::string& folderPath, const std::string& suffix) {
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            fs::path oldPath = entry.path();
            std::string stem = oldPath.stem().string();
            std::string extension = oldPath.extension().string();
            std::string newName = stem + suffix + extension;
            fs::rename(oldPath, oldPath.parent_path() / newName);
            std::cout << "Renamed: " << oldPath.filename().string() << " -> " << newName << "\n";
        }
    }
}

// Replace substring in filenames
void replaceSubstring(const std::string& folderPath, const std::string& from, const std::string& to) {
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            std::string oldName = entry.path().filename().string();
            size_t pos = oldName.find(from);
            if (pos != std::string::npos) {
                std::string newName = oldName;
                while ((pos = newName.find(from)) != std::string::npos) {
                    newName.replace(pos, from.length(), to);
                }
                fs::rename(entry.path(), entry.path().parent_path() / newName);
                std::cout << "Renamed: " << oldName << " -> " << newName << "\n";
            }
        }
    }
}

// Rename files as numbered sequence: 1.ext, 2.ext, ...
void renameNumbered(const std::string& folderPath) {
    int counter = 1;
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            fs::path oldPath = entry.path();
            std::string extension = oldPath.extension().string();
            std::string newName = std::to_string(counter++) + extension;
            fs::rename(oldPath, oldPath.parent_path() / newName);
            std::cout << "Renamed: " << oldPath.filename().string() << " -> " << newName << "\n";
        }
    }
}

// Convert filenames to uppercase
void renameUppercase(const std::string& folderPath) {
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            std::string oldName = entry.path().filename().string();
            std::string newName = oldName;
            std::transform(newName.begin(), newName.end(), newName.begin(), ::toupper);
            if (oldName != newName) {
                fs::rename(entry.path(), entry.path().parent_path() / newName);
                std::cout << "Renamed: " << oldName << " -> " << newName << "\n";
            }
        }
    }
}

// Convert filenames to lowercase
void renameLowercase(const std::string& folderPath) {
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            std::string oldName = entry.path().filename().string();
            std::string newName = oldName;
            std::transform(newName.begin(), newName.end(), newName.begin(), ::tolower);
            if (oldName != newName) {
                fs::rename(entry.path(), entry.path().parent_path() / newName);
                std::cout << "Renamed: " << oldName << " -> " << newName << "\n";
            }
        }
    }
}
