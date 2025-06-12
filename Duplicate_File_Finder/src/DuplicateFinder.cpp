#include "../include/DuplicateFinder.h"
#include "../include/FileHasher.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

DuplicateFinder::DuplicateFinder(const std::string& directory)
    : dirPath(directory) {}

void DuplicateFinder::findDuplicates() {
    for (const auto& entry : fs::recursive_directory_iterator(dirPath)) {
        if (fs::is_regular_file(entry)) {
            std::string path = entry.path().string();
            std::string hash = FileHasher::hashFile(path); 

            if (!hash.empty()) {
                hashMap[hash].push_back(path);
            }
        }
    }
}

void DuplicateFinder::printDuplicates() const {
    std::cout << "Duplicate Files Found:\n";
    bool found = false;

    for (const auto& pair : hashMap) {
        if (pair.second.size() > 1) {
            found = true;
            std::cout << "\nHash: " << pair.first << "\n";
            for (const auto& file : pair.second) {
                std::cout << " " << file << "\n";
            }
     }
    }

    if (!found) {
        std::cout << "No duplicate files found.\n";
    }
}

void DuplicateFinder::handleDuplicates(){
    std::string action;
    std::string moveFolder = dirPath + "/duplicates";

    fs::create_directories(moveFolder);

    for(const auto& pair:hashMap){
        if(pair.second.size() > 1 ){
            std::cout<< "\n Duplicate groups :\n";
            for(size_t i = 0; i < pair.second.size();++i){
                std::cout << "[" << i+1 <<"]" << pair.second[i] << "\n";
            }

            std::cout << "Action? (d = delete, m = move, s = skip): ";
            std::cin >> action;

            
            if (action == "d") {
               
                for (size_t i = 1; i < pair.second.size(); ++i) {
                    fs::remove(pair.second[i]);
                    std::cout << "Deleted: " << pair.second[i] << "\n";
                }
            }

             else if (action == "m") {
                for (size_t i = 1; i < pair.second.size(); ++i) {
                    fs::path dest = moveFolder + "/" + fs::path(pair.second[i]).filename().string();
                    fs::rename(pair.second[i], dest);
                    std::cout << "Moved: " << pair.second[i] << " → " << dest << "\n";
                }
            } 
            else {
                std::cout << "Skipped this group.\n";
            }
        }
    }
}
