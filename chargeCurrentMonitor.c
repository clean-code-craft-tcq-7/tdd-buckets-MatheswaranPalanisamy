#include <stdio.h>

#include "chargeCurrentPairsFinder.h"
#include "formatCurrentPairs.h"
#include "A2DConverter.h"

int getFormattedCurrentPairs(int *chrgeCurrentArray, int size, char *formattedBuffer)
{
    chargeCurrentPair currentPairs[MAX_CURRENT_PAIRS_SUPPORTED];

    int pairCount = findCurrentPairs(chrgeCurrentArray, size, currentPairs);
    int stringSize = formatCurrentPairInCsv(currentPairs, pairCount, formattedBuffer);

    return stringSize;
}

int getFormattedCurrentPairsFromADCSamples(int *inputsample, int sampleSize, char *formattedBuffer)
{
    int currentOutput[MAX_SAMPLES_SUPPORTED];
    int currentOutputCount = ConvertA2DSamplesToCurrent(inputsample, sampleSize, currentOutput);
    int stringSize = getFormattedCurrentPairs(currentOutput, currentOutputCount, formattedBuffer);

    return stringSize;
}

