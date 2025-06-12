#include "../include/DuplicateFinder.h"
#include <iostream>

int main(){

    std::string folderPath;
    std::cout << "Enter the folder path to scan for duplicate files: ";
    std::getline(std::cin, folderPath);

    DuplicateFinder finder(folderPath);
    finder.findDuplicates();
    finder.printDuplicates();
    
    char choice;
    std::cout << "\n Want to manage duplicates? (y/n): ";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        finder.handleDuplicates(); 
    }
    return 0;
}


// g++ src/main.cpp src/DuplicateFinder.cpp src/FileHasher.cpp -Iinclude -o duplicate_finder.exe -std=c++17

// ./duplicate_finder.exe 
