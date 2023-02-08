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

static int identifyCurrentPair(int *chrgeCurrentArray, int size)
{
    int index = 0;
    for(;index < size - 1; index++)
    {
        if(chrgeCurrentArray[index + 1] != (chrgeCurrentArray[index] + 1))
        {
            break;
        }
    }

    return index;
}

static int getValidCurrentPairs(int *chrgeCurrentArray, int size, chargeCurrentPair *pairBuffer)
{
    int index = 0, nextIndex = 0, pairCount = 0;

    while(index < size)
    {
        nextIndex = identifyCurrentPair(&chrgeCurrentArray[index], size - index);

        if(nextIndex > 0)
        {
            pairBuffer[pairCount].lower_limit = chrgeCurrentArray[index];
            pairBuffer[pairCount].upper_limit = chrgeCurrentArray[nextIndex];
            pairBuffer[pairCount].count = nextIndex - index + 1;

            index = nextIndex + 1;
            pairCount++;
        }
        else
        {
            break;
        }
    }

    return pairCount;
}

int findCurrentPairs(int *chrgeCurrentArray, int size, chargeCurrentPair *pairBuffer)
{
    int pairCount = 0;

    if(validateCurrentSampleArray(chrgeCurrentArray, size))
    {
        pairCount = getValidCurrentPairs(chrgeCurrentArray, size, pairBuffer);
    }    

    return pairCount;
}
