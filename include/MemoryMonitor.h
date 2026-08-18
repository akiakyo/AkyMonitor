#pragma once

class MemoryMonitor
{
public:

    MemoryMonitor();

    double getUsagePercentage();

    unsigned long long getTotalMemory();

    unsigned long long getUsedMemory();
};