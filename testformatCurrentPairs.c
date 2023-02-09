#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "formatCurrentPairs.h"

void testFormatCurrentPairInCsv(chargeCurrentPair *pairBuffer, int pairCount, char *outputBuffer, int bufferSize)
{
    char outputCsvString[250];
    int len = formatCurrentPairInCsv(pairBuffer, pairCount, outputCsvString);

    assert(len == bufferSize);

    if(bufferSize > 0)
    {
        assert(strncmp(outputBuffer, outputCsvString, bufferSize) == 0);
    }
}

void testformatCurrentPairs()
{
    // Test cases for Step 6
    testFormatCurrentPairInCsv(NULL, 5, "", 0);

    chargeCurrentPair currenPairInput[1] = {{4,5,2}};
    testFormatCurrentPairInCsv(currenPairInput, 0, "Range, Readings\n", 16);

    assert(formatCurrentPairInCsv(currenPairInput, 1, NULL) == 0);
    testFormatCurrentPairInCsv(currenPairInput, 1, "Range, Readings\n4-5, 2\n", 23);

    chargeCurrentPair currenPairInput1[2] = {{4,5,2}, {7,8,2}};
    testFormatCurrentPairInCsv(currenPairInput1, 2, "Range, Readings\n4-5, 2\n7-8, 2\n", 30);

    chargeCurrentPair currenPairInput2[5] = {{2,3,7}, {7,8,10}, {11,12,5}, {15,20,10}, {31,35,15}};
    testFormatCurrentPairInCsv(currenPairInput2, 5, "Range, Readings\n2-3, 7\n7-8, 10\n11-12, 5\n15-20, 10\n31-35, 15\n", 60);
}
