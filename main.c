#include <stdio.h>
#include <string.h>

#include "chargeCurrentmonitor.h"
#include "test_chargeCurrentmonitor.h"

int main()
{
    // Simple values
    int currentSamples1[] = {4,5};
    testCurrentMonitor(currentSamples1, 2, "Range, Readings\n4-5, 2\n", 23);
    // Misaligned simple values
    int currentSamples2[] = {5,4};
    testCurrentMonitor(currentSamples2, 2, "Range, Readings\n4-5, 2\n", 23);
    // Simple 3 values
    int currentSamples3[] = {2,3,4};
    testCurrentMonitor(currentSamples3, 3, "Range, Readings\n2-4, 3\n", 23);

    return 0;
}
