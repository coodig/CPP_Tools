#include "../include/LogCleaner.h"
#include <iostream>
#include <chrono>
#include <filesystem>

namespace fs= std::filesystem;

LogCleaner::LogCleaner(const std::string& directory, int daysThreshold)
: logDir(directory), thresholdDays(daysThreshold){

}

// bool LogCleaner::isOlderThan(const fs::path& filePath, int days) const{
//     auto ftime = fs::last_write_time(filePath);

//     #if defined(_MSC_VER)
//         auto sctp = decltype(ftime)::clock::to_sys(ftime);
//     #else
//         // Portable conversion from file_time_type to system_clock::time_point
//         auto sctp = std::chrono::system_clock::time_point(
//             std::chrono::duration_cast<std::chrono::system_clock::duration>(
//                 ftime.time_since_epoch()
//             )
//         );
//     #endif

//     auto now = std::chrono::system_clock::now();
//     auto age = std::chrono::duration_cast<std::chrono::hours>(now - sctp).count();
//     return age > (days * 24);
// }

bool LogCleaner::isOlderThan(const fs::path& filePath, int days) const {
    auto ftime = fs::last_write_time(filePath);

    // Convert file_time_type to system_clock::time_point for compatibility
    auto sctp = std::chrono::system_clock::time_point(
        std::chrono::duration_cast<std::chrono::system_clock::duration>(
            ftime.time_since_epoch()
        )
    );

    auto now = std::chrono::system_clock::now();
    auto age = std::chrono::duration_cast<std::chrono::hours>(now - sctp).count();

    // Optional debug log
    std::cout << "File: " << filePath.filename() << " | Age (days): " << age << std::endl;

    return age > (days);
}


void LogCleaner::logScan(){
    oldLogfiles.clear();

    for(const auto& entry : fs::recursive_directory_iterator(logDir)){
        if(fs::is_regular_file(entry) && entry.path().extension() == ".log"){
            if(isOlderThan(entry.path(), thresholdDays)){
                oldLogfiles.push_back(entry.path());
            }
        }
    }
}

void LogCleaner::logShow()const{
    if(oldLogfiles.empty()){
        std::cout<< "no files to delete.\n";
        return;
    }

    std::string choice;
    std::cout<<"\n Do you really want to delete all thesse files?? (y/n)";
    std::cin>>choice;

    if(choice == "y" || choice == "Y"){
        for(const auto& file : oldLogfiles){
            fs::remove(file);
            std::cout<< "Deleted: "<< file<<"\n";
        }
    }else{
        std::cout<<"cleanup skipped.\n";
    }
}