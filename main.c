#include <stdio.h>

#include "testChargeCurrentPairsFinder.h"
#include "testformatCurrentPairs.h"
#include "testChargeCurrentMonitor.h"

int main()
{
    testCurrentPairsFinder();
    testformatCurrentPairs();
    testChargeCurrentMonitor();

    return 0;
}
