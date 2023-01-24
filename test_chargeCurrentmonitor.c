#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "chargeCurrentmonitor.h"

void testCurrentMonitor(int chrgeCurrentArray[], int size, char *expectedString, int charLength)
{
    char ccm_pair_output[100];
    int output_size = 0;
    memset(ccm_pair_output, 0, 100);
    output_size = findCurrentPairs(chrgeCurrentArray, size, ccm_pair_output);
    assert(strcmp(ccm_pair_output, expectedString));
    assert(output_size == charLength);
}
