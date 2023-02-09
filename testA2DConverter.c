#include <stdio.h>
#include <assert.h>

#include "A2DConverter.h"


void testA2DConverter()
{
    assert(validateA2DSample(-1) == 0);
    assert(validateA2DSample(0) == 1);
    assert(validateA2DSample(4000) == 1);
    assert(validateA2DSample(4094) == 1);
    assert(validateA2DSample(4095) == 0);

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

}
