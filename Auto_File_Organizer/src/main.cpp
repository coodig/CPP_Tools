#include <iostream>
#include <filesystem>
#include <unordered_map>
#include "../../common/file_utils.h"
#include "../../common/logger.h"

namespace fs = std::filesystem;

// Extension map for categorization
std::unordered_map<std::string, std::string> extensionMap = {
    {".jpg", "Images"}, {".jpeg", "Images"}, {".png", "Images"}, {".gif", "Images"},
    {".mp4", "Videos"}, {".mkv", "Videos"}, {".avi", "Videos"},
    {".pdf", "Documents"}, {".docx", "Documents"}, {".txt", "Documents"},
    {".zip", "Archives"}, {".rar", "Archives"},
    {".exe", "Applications"}, {".apk", "Applications"}
};

// Category finder
// std::string getCategory(const fs::path& file) {
//     auto ext = file.extension().string();
//     if (extensionMap.count(ext)) return extensionMap[ext];
//     return "Others";
// }

std::pair<std::string, std::string> getCategory(const fs::path& file) {
    auto ext = file.extension().string();
    if (extensionMap.count(ext)) {
        return {extensionMap[ext], ext.substr(1)};  // {"Images", "png"}
    }
    return {"Others", "misc"};
}

// Organizer function
void organizeFiles(const fs::path& targetDir) {
    if (!fs::exists(targetDir) || !fs::is_directory(targetDir)) {
        logError("Invalid directory.");
        return;
    }

    for (const auto& entry : fs::directory_iterator(targetDir)) {
        if (fs::is_regular_file(entry.status())) {
            // std::string category = getCategory(entry.path());
            // fs::path destDir = targetDir / category;
              auto [category, subfolder] = getCategory(entry.path());
        fs::path destDir = targetDir / category / subfolder;

            if (createFolderIfNotExists(destDir.string())) {
                fs::path destination = destDir / entry.path().filename();
                if (moveFile(entry.path().string(), destination.string())) {
                    logSuccess("Moved: " + entry.path().filename().string() + " -> " + category);
                } else {
                    logError("Failed to move: " + entry.path().filename().string());
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        logInfo("Usage: " + std::string(argv[0]) + " <directory_path>");
        return 1;
    }

    // clearConsole();
    std::cout << "Directory is already organized...";
    fs::path targetDir = argv[1];
    organizeFiles(targetDir);
    return 0;
}

// It's jus example so that u can understand that how we can execute it:-


// PS C:\Users\nehab\Desktop\c++ tools\Auto_File_Organizer\src> g++ -std=c++17 main.cpp ../../common/file_utils.cpp ../../common/logger.cpp -o organizer.exe

// PS C:\Users\nehab\Desktop\c++ tools\Auto_File_Organizer\src> .\organizer.exe "E:\desktop 23-10-24\camerea"