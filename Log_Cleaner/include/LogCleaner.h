#pragma once
#include <vector>
#include <string>
#include <filesystem>

class LogCleaner{
public:
    LogCleaner(const std::string& directory, int daysThreshold = 30 );
    void logScan();
    void logShow()const;
    void logClean();

private:
    std::string logDir;
    int thresholdDays;
    std::vector<std::filesystem::path> oldLogfiles;

    bool isOlderThan(const std::filesystem::path& filePath, int days) const;

};