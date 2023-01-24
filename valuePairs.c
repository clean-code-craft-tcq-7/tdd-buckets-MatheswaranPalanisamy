#include <stdio.h>
#include "valuePairs.h"

static int isValueInRange(int value, int min, int max)
{
    if(value >= min)
    {
        return 1;
    }
    else if(value <= max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static void sortValue(int *chrgeCurrentArray, int size)
{
    int index1 = 0, index2 = 0;
    int tempValue = 0;
    for(index1 = 0; index1 < size; index1++)
    {
        for(index2 = index1 + 1; index2 < size; index2++)
        {
            if(chrgeCurrentArray[index1] > chrgeCurrentArray[index2])
            {
                tempValue = chrgeCurrentArray[index1];
                chrgeCurrentArray[index1] = chrgeCurrentArray[index2];
                chrgeCurrentArray[index2] = tempValue;
            }
        }
    }
}

valuePair findValuePair(int *chrgeCurrentArray, int size)
{
    valuePair valuePair;
    sortValue(chrgeCurrentArray, size);
    valuePair.pair_startValue = chrgeCurrentArray[0];
    valuePair.pair_endvalue = chrgeCurrentArray[1];

    return valuePair;
}

int findPairCount(int *chrgeCurrentArray, int size, valuePair valuePair)
{
    int index = 0;
    int pairCount = 0;

    for(index = 0; index < size; index++)
    {
        if(isValueInRange(chrgeCurrentArray[size], valuePair.pair_startValue, valuePair.pair_endvalue))
        {
            pairCount++;
        }
    }

    return pairCount;
}
