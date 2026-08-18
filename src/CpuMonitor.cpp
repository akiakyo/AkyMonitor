#include "CpuMonitor.h"

#include <windows.h>

CpuMonitor::CpuMonitor()
{
    previousIdleTime = 0;
    previousKernelTime = 0;
    previousUserTime = 0;
}


double CpuMonitor::getUsage()
{
    FILETIME idleTime;
    FILETIME kernelTime;
    FILETIME userTime;

    if (!GetSystemTimes(
        &idleTime,
        &kernelTime,
        &userTime))
    {
        return 0.0;
    }


    ULARGE_INTEGER idle;
    ULARGE_INTEGER kernel;
    ULARGE_INTEGER user;


    idle.LowPart = idleTime.dwLowDateTime;
    idle.HighPart = idleTime.dwHighDateTime;

    kernel.LowPart = kernelTime.dwLowDateTime;
    kernel.HighPart = kernelTime.dwHighDateTime;

    user.LowPart = userTime.dwLowDateTime;
    user.HighPart = userTime.dwHighDateTime;


    unsigned long long idleDiff =
        idle.QuadPart - previousIdleTime;

    unsigned long long kernelDiff =
        kernel.QuadPart - previousKernelTime;

    unsigned long long userDiff =
        user.QuadPart - previousUserTime;


    previousIdleTime = idle.QuadPart;
    previousKernelTime = kernel.QuadPart;
    previousUserTime = user.QuadPart;


    unsigned long long total =
        kernelDiff + userDiff;


    if (total == 0)
        return 0;


    double usage =
        100.0 *
        (double)(total - idleDiff)
        /
        (double)total;


    return usage;
}