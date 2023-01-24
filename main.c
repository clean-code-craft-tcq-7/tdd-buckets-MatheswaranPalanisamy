#include <stdio.h>
#include <string.h>

#include "chargeCurrentmonitor.h"
#include "test_chargeCurrentmonitor.h"

int main()
{
    int currentSamples[] = {4,5};
    testCurrentMonitor(currentSamples, 2, "Range, Readings\n4-5, 2\n", 23);
    return 0;
}
