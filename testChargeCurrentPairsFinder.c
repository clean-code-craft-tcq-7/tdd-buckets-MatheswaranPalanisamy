#include <stdio.h>
#include <assert.h>

#include "chargeCurrentPairsFinder.h"

void testCurrentPairOutput(int *chrgeCurrentArray, int inputSize, chargeCurrentPair *pairBuffer, int outputSize)
{
    chargeCurrentPair outputBuffer[MAX_CURRENT_PAIRS_SUPPORTED];
    assert(findCurrentPairs(chrgeCurrentArray, inputSize, outputBuffer) == outputSize);

    int index = 0;
    for(;index < outputSize; index++)
    {
        assert(outputBuffer[index].lower_limit == pairBuffer[index].lower_limit);
        assert(outputBuffer[index].upper_limit == pairBuffer[index].upper_limit);
        assert(outputBuffer[index].count == pairBuffer[index].count);
    }
}
