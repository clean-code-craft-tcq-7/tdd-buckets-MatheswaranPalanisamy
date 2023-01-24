#include <stdio.h>
#include "valuePairs.h"
#include "formatPairs.h"

#include "chargeCurrentmonitor.h"

int findCurrentPairs(int *chrgeCurrentArray, int size, char *pairBuffer)
{
    valuePair valuePairs = findValuePair(chrgeCurrentArray, size);
    valuePairs.pair_count = findPairCount(chrgeCurrentArray, size, valuePairs);

    int charCount = getFormattedPairs(valuePairs, pairBuffer);

    return charCount;
}
