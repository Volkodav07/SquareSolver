#define EPSILON 1e-9

#include <math.h>
#include "../headers/Comparing.h"

int Compare_with_zero (double x)  // comparing coeffs with zero
{
    if (fabs(x) < EPSILON) return 0;
    else if (x < EPSILON) return -1;
    else return 1;
}
