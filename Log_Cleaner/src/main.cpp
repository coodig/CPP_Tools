// #include <iostream>
// #include "../include/LogCleaner.h"
// #include <string>

// int main(){
//     std::string path;
//     int days;

//     std::cout<<"Enter log directory path: \n";
//     std::getline(std::cin, path);
    
//     std::cout<<"Enter log directory days: \n";
//     std::cin>>days;

//     LogCleaner  cleaner(path, days);

//     cleaner.logScan();
//     cleaner.logShow();
//     // cleaner.logClean();

//     return 0;
    





// }


#include "../include/LogCleaner.h"
#include <iostream>
#include <string>

int main() {
    std::string directory;
    int days = 30;

    std::cout << "Enter path of log directory: ";
    std::getline(std::cin, directory);

    std::cout << "Enter threshold days (default 30): ";
    std::string input;
    std::getline(std::cin, input);
    if (!input.empty()) {
        days = std::stoi(input);
    }

    LogCleaner cleaner(directory, days);
    cleaner.logScan();
    cleaner.logShow();

    return 0;
}
// g++ src/main.cpp src/LogCleaner.cpp -Iinclude -o bin/LogCleaner.exe
