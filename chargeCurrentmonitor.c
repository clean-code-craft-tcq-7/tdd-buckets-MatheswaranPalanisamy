#include <stdio.h>
#include "chargeCurrentmonitor.h"

static int validateCurrentSampleArray(int *chrgeCurrentArray, int size)
{
    if(size < 2)
    {
        return 0;
    }

    if(chrgeCurrentArray == NULL)
    {
        return 0;
    }

    return 1;
}

int findCurrentPairs(int *chrgeCurrentArray, int size, chargeCurrentPair *pairBuffer)
{
    int pairCount = 0;
    if(validateCurrentSampleArray(chrgeCurrentArray, size))
    {
        pairBuffer[0].lower_limit = chrgeCurrentArray[0];
        pairBuffer[0].upper_limit = chrgeCurrentArray[size - 1];
        pairBuffer[0].count = size;

        pairCount = 1;
    }

    return pairCount;
}
