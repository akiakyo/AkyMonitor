#pragma once
#include <string>
class SystemInfo {
public:
    std::string getDeviceName();
    std::string getProcessor();
    std::string getInstalledRam();
    std::string getSystemType();
};
