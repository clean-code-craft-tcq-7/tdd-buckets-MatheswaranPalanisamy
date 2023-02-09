#include <stdio.h>
#include <assert.h>

#include "A2DConverter.h"

void testConvertA2DSamplesToCurrent(int *inputsample, int sampleSize, int *outputsample, int outputSize)
{
    int outputCurrentArray[100];
    int outputCnt = ConvertA2DSamplesToCurrent(inputsample, sampleSize, outputCurrentArray);
    int index = 0;

    assert(outputCnt == outputSize);
    for(;index < outputSize; index++)
    {
        assert(outputsample[index] == outputCurrentArray[index]);
    }
}

void testA2DConverter()
{
    // Test case for step 7
    assert(validateA2DSample(-1) == 0);
    assert(validateA2DSample(0) == 1);
    assert(validateA2DSample(4000) == 1);
    assert(validateA2DSample(4094) == 1);
    assert(validateA2DSample(4095) == 0);

    // Test case for step 8
    assert(convertA2DSample(-5) == -1);
    assert(convertA2DSample(-1) == -1);
    assert(convertA2DSample(0) == 0);
    assert(convertA2DSample(100) == 0);
    assert(convertA2DSample(210) == 1);
    assert(convertA2DSample(1800) == 4);
    assert(convertA2DSample(2047) == 5);
    assert(convertA2DSample(4000) == 10);
    assert(convertA2DSample(4094) == 10);
    assert(convertA2DSample(4095) == -1);
    assert(convertA2DSample(5000) == -1);

    // Test case for step 9
    int inputSampleArray[2] = {-50, 5000};
    int outputCurrentArray[1];
    testConvertA2DSamplesToCurrent(inputSampleArray, 2, outputCurrentArray, 0);

    int inputSampleArray1[9] = {0, 300, 500, 1780, 900, 2010, 3750, 4001, 4094};
    int outputCurrentArray1[9] = {0, 1, 1, 4, 2, 5, 9, 10, 10};
    testConvertA2DSamplesToCurrent(inputSampleArray1, 9, outputCurrentArray1, 9);

    int inputSampleArray2[9] = {0, 300, -50, 1780, 900, 4900, 3750, 4001, 4094};
    int outputCurrentArray2[7] = {0, 1, 4, 2, 9, 10, 10};
    testConvertA2DSamplesToCurrent(inputSampleArray2, 9, outputCurrentArray2, 7);
}
