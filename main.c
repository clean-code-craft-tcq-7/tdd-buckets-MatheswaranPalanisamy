#include <stdio.h>
#include <assert.h>

#include "chargeCurrentmonitor.h"

int main()
{
    // Test case for Step 1
    chargeCurrentPair outputArray[20];
    assert(findCurrentPairs(NULL, 5, outputArray) == 0);
    int currentPairArray1[1];
    assert(findCurrentPairs(currentPairArray1, 0, outputArray) == 0);
    int currentPairArray2[1] = {3};
    assert(findCurrentPairs(currentPairArray2, 1, outputArray) == 0);

    // Test case for Step 2
    int currentPairArray3[2] = {4, 5};
    assert(findCurrentPairs(currentPairArray3, 2, outputArray) == 1);
    assert(outputArray[0].lower_limit == 4);
    assert(outputArray[0].upper_limit == 5);
    assert(outputArray[0].count == 3);

    int currentPairArray4[6] = {4,5,6,7,8,9};
    assert(findCurrentPairs(currentPairArray4, 6, outputArray) == 1);
    assert(outputArray[0].lower_limit == 4);
    assert(outputArray[0].upper_limit == 9);
    assert(outputArray[0].count == 6);

    return 0;
}
