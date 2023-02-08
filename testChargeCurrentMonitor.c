#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "chargeCurrentMonitor.h"

void testFormatChargeCurrentMonitor(int *chrgeCurrentArray, int size, char *outputBuffer, int bufferSize)
{
    char outputCsvString[250];
    int len = getFormattedCurrentPairs(chrgeCurrentArray, size, outputCsvString);

    assert(len == bufferSize);

    if(bufferSize > 0)
    {
        assert(strncmp(outputBuffer, outputCsvString, bufferSize) == 0);
    }
}

void testChargeCurrentMonitor()
{
    testFormatChargeCurrentMonitor(NULL, 15, "Range, Readings\n", 16);
    int currentPairArray1[1];
    testFormatChargeCurrentMonitor(currentPairArray1, 0, "Range, Readings\n", 16);

    int currentPairArray2[1] = {3};
    testFormatChargeCurrentMonitor(currentPairArray2, 0, "Range, Readings\n", 16);
    
    int currentPairArray3[2] = {4, 5};
    testFormatChargeCurrentMonitor(currentPairArray3, 2, "Range, Readings\n4-5, 2\n", 23);
    
    int currentPairArray4[4] = {7, 4, 5, 8};
    testFormatChargeCurrentMonitor(currentPairArray4, 4, "Range, Readings\n4-5, 2\n7-8, 2\n", 30);
    
    int currenPairInput5[7] = {10, 3, 4, 5, 7, 9, 8};
    testFormatChargeCurrentMonitor(currenPairInput5, 7, "Range, Readings\n3-5, 3\n7-10, 4\n", 31);
}
