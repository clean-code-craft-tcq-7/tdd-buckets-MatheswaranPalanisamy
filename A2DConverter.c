#include <stdio.h>
#include <math.h>

#include "A2DConverter.h"

int validateA2DSample(int sample)
{
    if((sample >= A2D_SAMPLE_MIN_VALUE) && (sample <= A2D_SAMPLE_MAX_VALUE))
    {
        return 1;
    }

    return 0;
}

int convertA2DSample(int sample)
{
    int current = -1;
    float currentFloat = 0;

    if(validateA2DSample(sample) == 1)
    {
        currentFloat = (float)sample * MAX_CURRENT_VALUE / (float)A2D_SAMPLE_MAX_VALUE;
        current = (int)round(currentFloat);
    }

    return current;
}
