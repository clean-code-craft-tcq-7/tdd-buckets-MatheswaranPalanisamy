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
}
