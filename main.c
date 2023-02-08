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
    assert(outputArray[0].count == 2);

    int currentPairArray4[6] = {4, 5, 6, 7, 8, 9};
    assert(findCurrentPairs(currentPairArray4, 6, outputArray) == 1);
    assert(outputArray[0].lower_limit == 4);
    assert(outputArray[0].upper_limit == 9);
    assert(outputArray[0].count == 6);

    // Test case for Step 3
    int currentPairArray5[7] = {1, 2, 3, 7, 8, 9, 10};
    assert(findCurrentPairs(currentPairArray5, 7, outputArray) == 2);
    assert(outputArray[0].lower_limit == 1);
    assert(outputArray[0].upper_limit == 3);
    assert(outputArray[0].count == 3);
    assert(outputArray[1].lower_limit == 7);
    assert(outputArray[1].upper_limit == 10);
    assert(outputArray[1].count == 4);

    int currentPairArray6[8] = {1, 2, 3, 7, 8, 9, 11, 12};
    assert(findCurrentPairs(currentPairArray6, 8, outputArray) == 3);
    assert(outputArray[0].lower_limit == 1);
    assert(outputArray[0].upper_limit == 3);
    assert(outputArray[0].count == 3);
    assert(outputArray[1].lower_limit == 7);
    assert(outputArray[1].upper_limit == 9);
    assert(outputArray[1].count == 3);
    assert(outputArray[2].lower_limit == 11);
    assert(outputArray[2].upper_limit == 12);
    assert(outputArray[2].count == 2);

    // Test case for Step 4
    int currentPairArray7[2] = {3, 2};
    assert(findCurrentPairs(currentPairArray7, 2, outputArray) == 1);
    assert(outputArray[0].lower_limit == 2);
    assert(outputArray[0].upper_limit == 3);
    assert(outputArray[0].count == 2);

    int currentPairArray8[5] = {6, 4, 7, 8, 5};
    assert(findCurrentPairs(currentPairArray8, 5, outputArray) == 1);
    assert(outputArray[0].lower_limit == 4);
    assert(outputArray[0].upper_limit == 8);
    assert(outputArray[0].count == 5);

    int currentPairArray9[7] = {7, 8, 3, 12, 2, 9, 11};
    assert(findCurrentPairs(currentPairArray9, 7, outputArray) == 3);
    assert(outputArray[0].lower_limit == 2);
    assert(outputArray[0].upper_limit == 3);
    assert(outputArray[0].count == 2);
    assert(outputArray[1].lower_limit == 7);
    assert(outputArray[1].upper_limit == 9);
    assert(outputArray[1].count == 3);
    assert(outputArray[2].lower_limit == 11);
    assert(outputArray[2].upper_limit == 12);
    assert(outputArray[2].count == 2);

    return 0;
}
