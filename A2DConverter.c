#include <stdio.h>

#include "A2DConverter.h"

int validateA2DSample(int sample)
{
    if((sample >= A2D_SAMPLE_MIN_VALUE) && (sample <= A2D_SAMPLE_MAX_VALUE))
    {
        return 1;
    }

    return 0;
}
