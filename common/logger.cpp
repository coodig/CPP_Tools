#include "logger.h"
#include <iostream>

void logInfo(const std::string& msg) {
    std::cout << "[INFO] " << msg << std::endl;
}

void logError(const std::string& msg) {
    std::cerr << "\033[1;31m[ERROR]\033[0m " << msg << std::endl;
}

void logSuccess(const std::string& msg) {
    std::cout << "\033[1;32m[SUCCESS]\033[0m " << msg << std::endl;
}

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
