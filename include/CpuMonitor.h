#pragma once

class CpuMonitor
{
public:
    CpuMonitor();

    double getUsage();

private:
    unsigned long long previousIdleTime;
    unsigned long long previousKernelTime;
    unsigned long long previousUserTime;
};