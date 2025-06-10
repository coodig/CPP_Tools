// #include <iostream>
// #include <string>
// #include <vector>
// #include <filesystem>
// #include "logger.h"
// #include "renamer.h"
// #include "file_utils.h"

// namespace fs = std::filesystem;

// int main() {
//     std::string dirctoryPath;
//     std::string extension;
//     std::string newBaseName;

//     std::cout<<"Enter directory path: ";
//     std::getline(std::cin, dirctoryPath);

//     if(!fs::exists(dirctoryPath) ||!fs::is_directory(dirctoryPath)){
//         logError("directory is not valid or no exist..");
//         return 1;
//     }

//     std::cout<<"Enter extension : ";
//     std::cin>>extension;

//     std::cout<<"Enter new base name: ";
//     std::cin>>newBaseName;

//     std::vector<fs::directory_entry> files = getFilesWithExtension(dirctoryPath, extension);

//     if(files.empty()){
//         logInfo("no files found with given extension");
//         return 0;
//     }

//     // renameFiles(files, newBaseName, dirctoryPath);
//     batchRenameFiles(path, extension, newBaseName);


//     return 0;
// }


#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include "logger.h"
#include "file_utils.h"

namespace fs = std::filesystem;

int main() {
    std::string directoryPath;
    std::string extension;
    std::string newBaseName;

    std::cout << "Enter directory path: ";
    std::getline(std::cin, directoryPath);

    if (!fs::exists(directoryPath) || !fs::is_directory(directoryPath)) {
        logError("Directory is not valid or does not exist.");
        return 1;
    }

    std::cout << "Enter extension (e.g. .txt): ";
    std::cin >> extension;

    std::cout << "Enter new base name: ";
    std::cin >> newBaseName;

    std::vector<fs::directory_entry> files = getFilesWithExtension(directoryPath, extension);

    if (files.empty()) {
        logInfo("No files found with the given extension.");
        return 0;
    }

    if (renameFiles(files, newBaseName, extension)) {
        logSuccess("All files renamed successfully.");
    } else {
        logError("Some files could not be renamed.");
    }

    return 0;
}
