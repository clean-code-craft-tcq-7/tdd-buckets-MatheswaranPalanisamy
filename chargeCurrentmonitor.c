#include <stdio.h>
#include <stdlib.h>

#include "chargeCurrentmonitor.h"

int ascendingComparator(const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b );
}

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
    int firstElement = chrgeCurrentArray[0];
    int lastElement = chrgeCurrentArray[0];
    for(;index < size - 1; index++)
    {
        if((chrgeCurrentArray[index + 1] - chrgeCurrentArray[index]) > 1)
        {
            break;
        }
    }

    lastElement = chrgeCurrentArray[index];

    if(firstElement == lastElement)
    {
        return 0;
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
            pairBuffer[pairCount].upper_limit = chrgeCurrentArray[index + nextIndex];
            pairBuffer[pairCount].count = nextIndex + 1;

            index += nextIndex + 1;
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
        qsort(chrgeCurrentArray, size, sizeof(int), ascendingComparator);
        pairCount = getValidCurrentPairs(chrgeCurrentArray, size, pairBuffer);
    }

    return pairCount;
}
