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

void testFormattedCurrentPairsFromADCSamples(int *samplesArray, int size, char *outputBuffer, int bufferSize)
{
    char outputCsvString[250];
    int len = getFormattedCurrentPairsFromADCSamples(samplesArray, size, outputCsvString);

    assert(len == bufferSize);

    if(bufferSize > 0)
    {
        assert(strncmp(outputBuffer, outputCsvString, bufferSize) == 0);
    }
}

void testChargeCurrentMonitor()
{
    // Test cases for Step 6
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

    // Test cases for Step 10
    int A2DSampleArray2[1] = {1000};
    testFormattedCurrentPairsFromADCSamples(A2DSampleArray2, 1, "Range, Readings\n", 16);
    
    int A2DSampleArray3[3] = {-5, 999, 970};
    testFormattedCurrentPairsFromADCSamples(A2DSampleArray3, 3, "Range, Readings\n", 16);

    int A2DSampleArray4[8] = {1790, 5800, 2305, 2250, 1788, 2200, 2180, -1};
    testFormattedCurrentPairsFromADCSamples(A2DSampleArray4, 8, "Range, Readings\n4-6, 6\n", 23);
    
    int A2DSampleArray5[4] = {2900, 1725, 2138, 3211};
    testFormattedCurrentPairsFromADCSamples(A2DSampleArray5, 4, "Range, Readings\n4-5, 2\n7-8, 2\n", 30);
    
    int A2DSampleArray6[7] = {3982, 1231, 1732, 2023, 2918, 3715, 3327};
    testFormattedCurrentPairsFromADCSamples(A2DSampleArray6, 7, "Range, Readings\n3-5, 3\n7-10, 4\n", 31);

    int A2DSampleArray7[10] = {3982, 1231, 5, 1732, 2023, 2918, 237, 3715, 3327, 98};
    testFormattedCurrentPairsFromADCSamples(A2DSampleArray7, 10, "Range, Readings\n0-1, 3\n3-5, 3\n7-10, 4\n", 38);
}
