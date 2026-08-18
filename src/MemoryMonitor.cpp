#include "MemoryMonitor.h"

#include <windows.h>


MemoryMonitor::MemoryMonitor()
{

}


double MemoryMonitor::getUsagePercentage()
{
    MEMORYSTATUSEX memoryStatus;

    memoryStatus.dwLength =
        sizeof(MEMORYSTATUSEX);


    if(GlobalMemoryStatusEx(&memoryStatus))
    {
        return static_cast<double>(
            memoryStatus.dwMemoryLoad
        );
    }


    return 0.0;
}



unsigned long long MemoryMonitor::getTotalMemory()
{
    MEMORYSTATUSEX memoryStatus;

    memoryStatus.dwLength =
        sizeof(MEMORYSTATUSEX);


    if(GlobalMemoryStatusEx(&memoryStatus))
    {
        return memoryStatus.ullTotalPhys;
    }


    return 0;
}



unsigned long long MemoryMonitor::getUsedMemory()
{
    MEMORYSTATUSEX memoryStatus;

    memoryStatus.dwLength =
        sizeof(MEMORYSTATUSEX);


    if(GlobalMemoryStatusEx(&memoryStatus))
    {
        return
        memoryStatus.ullTotalPhys -
        memoryStatus.ullAvailPhys;
    }


    return 0;
}