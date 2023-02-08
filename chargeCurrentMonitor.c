#include <stdio.h>

#include "chargeCurrentPairsFinder.h"
#include "formatCurrentPairs.h"

int getFormattedCurrentPairs(int *chrgeCurrentArray, int size, char *formattedBuffer)
{
    chargeCurrentPair currentPairs[MAX_CURRENT_PAIRS_SUPPORTED];

    int pairCount = findCurrentPairs(chrgeCurrentArray, size, currentPairs);
    int stringSize = formatCurrentPairInCsv(currentPairs, pairCount, formattedBuffer);

    return stringSize;
}
