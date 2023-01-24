#include <stdio.h>
#include "valuePairs.h"
#include "formatPairs.h"

int getFormattedPairs(valuePair valuePair, char *pairBuffer)
{
    int charCount = 0;
    charCount = sprintf(pairBuffer, "%s\n", CURRENT_MONITOR_HEADER);
    charCount += sprintf(pairBuffer, "%d-%d, %d\n", valuePair.pair_startValue, valuePair.pair_endvalue, valuePair.pair_count);
    
    return charCount;
}
