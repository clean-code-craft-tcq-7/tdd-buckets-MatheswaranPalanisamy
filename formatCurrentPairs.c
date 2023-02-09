#include <stdio.h>
#include <string.h>

#include "formatCurrentPairs.h"

static int validateInputBuffer(chargeCurrentPair *pairBuffer)
{
    if(pairBuffer != NULL)
    {
        return 1;
    }

    return 0;
}

static int validateOutputBuffer(char *formattedBuffer)
{
    if(formattedBuffer != NULL)
    {
        return 1;
    }

    return 0;
}

static int formatSinglePair(chargeCurrentPair pairBuffer, char *formattedBuffer)
{
    int charCount = 0;
    charCount = sprintf(formattedBuffer, "%d-%d, %d\n", pairBuffer.lower_limit, pairBuffer.upper_limit, pairBuffer.count);

    return charCount;
}

static int formatCurrentPairs(chargeCurrentPair *pairBuffer, int pairCount, char *formattedBuffer)
{
    int charCount = 0, index = 0;
    for(;index < pairCount; index++)
    {
        charCount += formatSinglePair(pairBuffer[index], &formattedBuffer[charCount]);
    }

    return charCount;
}

int formatCurrentPairInCsv(chargeCurrentPair *pairBuffer, int pairCount, char *formattedBuffer)
{
    int charCount = 0;
    int inputOutputValidity = validateInputBuffer(pairBuffer) & validateOutputBuffer(formattedBuffer);

    if(inputOutputValidity)
    {
        charCount = sprintf(formattedBuffer, "%s\n", CURRENT_MONITOR_HEADER);
        charCount += formatCurrentPairs(pairBuffer, pairCount, &formattedBuffer[charCount]);
    }

    return charCount;
}
