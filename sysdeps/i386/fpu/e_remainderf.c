#include <libm-alias-finite.h>
#include <math.h>

float __ieee754_remainderf(float x, float y) {
    return remainderf(x, y);
}

libm_alias_finite (__ieee754_remainderf, __remainderf)
