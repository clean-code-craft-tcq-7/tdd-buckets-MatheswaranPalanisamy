#include <stdio.h>

#include "testChargeCurrentPairsFinder.h"
#include "testformatCurrentPairs.h"
#include "testChargeCurrentMonitor.h"
#include "testA2DConverter.h"

int main()
{
    testCurrentPairsFinder();
    testformatCurrentPairs();
    testChargeCurrentMonitor();
    testA2DConverter();
    
    return 0;
}
