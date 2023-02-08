#include <stdio.h>
#include <assert.h>

#include "chargeCurrentmonitor.h"

int main()
{
    chargeCurrentPair outputArray[20];
    assert(findCurrentPairs(NULL, 5, outputArray) == 0);
    int currentPairArray1[1];
    assert(findCurrentPairs(currentPairArray1, 0, outputArray) == 0);
    int currentPairArray2[1] = {3};
    assert(findCurrentPairs(currentPairArray2, 1, outputArray) == 0);

    return 0;
}
