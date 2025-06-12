#pragma once
#include <string>
#include <unordered_map>
#include <vector>

class DuplicateFinder
{
public:
    DuplicateFinder(const std::string& directory);
    void findDuplicates();
    void printDuplicates() const;
    void handleDuplicates();


private:
    std::string dirPath;
    std::unordered_map<std::string , std::vector<std::string>> hashMap;
};

