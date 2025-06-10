// #include "renamer.h"
// #include "../../common/logger.h"
// #include <iostream>
// #include <string>
// #include <sstream>
// #include <filesystem>

// using namespace std;

// namespace fs = std::filesystem;

// void batchRenameFiles(const std::string& directoryPath, const std::string& extension, const std::string& newBaseName){
//     if(!fs::exists(directoryPath) || !fs::is_directory(directoryPath)){
//         logError("Invalid directory path");
//         return;
//     }

//     int counter = 1;

//     for(const auto& entry: fs::directory_iterator(directoryPath)){
//         if(fs::is_regular_file(entry.status())){
//             std::string currentExtension = entry.path().extension().string();
//             if(currentExtension == extension){
//                 std::ostringstream newFileName;
//                 newFileName << newBaseName << "_" << counter << extension;
                
//                 fs::path newFilePath = entry.path().parent_path() / newFileName.str();

//                 try
//                 {
//                     fs::rename(entry.path(), newFilePath);
//                     logSuccess("Renamed: " + entry.path().filename().string() + "->"  + newFileName.str());
//                     counter++;
//                 }
//                 catch(const std::exception& e)
//                 {
//                     logError("Failed to rename: " + entry.path().filename().string());
//                 }
//             }
//         }
//     }   
//     if (counter == 1) {
//         logInfo("No files with extension '" + extension + "' found in the directory.");
//     }
// }

#include "renamer.h"
#include "logger.h"
#include <iostream>
#include <string>
#include <sstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void batchRenameFiles(const std::string& directoryPath, const std::string& extension, const std::string& newBaseName){
    if (!fs::exists(directoryPath) || !fs::is_directory(directoryPath)) {
        logError("Invalid directory path: " + directoryPath);
        return;
    }

    int counter = 1;

    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (fs::is_regular_file(entry.status())) {
            std::string currentExtension = entry.path().extension().string();
            if (currentExtension == extension) {
                std::ostringstream newFileName;
                newFileName << newBaseName << "_" << counter << extension;

                // fs::path newFilePath = fs::path(directoryPath) / newFileName.str();  // safer than entry.path().parent_path()

                fs::path dirPath(directoryPath);
                fs::path newFilePath = dirPath / fs::path(newFileName.str()).filename();


                try {
                    fs::rename(entry.path(), newFilePath);
                    logSuccess("Renamed: " + entry.path().filename().string() + " -> " + newFileName.str());
                    counter++;
                } catch (const fs::filesystem_error& e) {
                    logError("Failed to rename: " + entry.path().filename().string() + " -> " + e.what());
                }
            }
        }
    }

    if (counter == 1) {
        logInfo("No files with extension '" + extension + "' found in the directory.");
    }
}
