#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "chargeCurrentmonitor.h"

int main()
{
    int current_pair[2] = {4,5};
    char ccp_pair_output[100];
    int output_size = 0;
    memset(ccp_pair_output, 0, 100);
    output_size = findCurrentPairs(current_pair, 2, ccp_pair_output);
    assert(strcmp(ccp_pair_output, "Range, Readings\n4-5, 2\n"));
    assert(output_size == 23);
    return 0;
}
