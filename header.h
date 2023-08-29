#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#define EPSILON 1e-9

#include "colors.h"
#include "equation_solver.h"
#include "Test.h"

int Get_coeffs (double *a, double *b, double *c, int *nRoots);
int Printing_roots (double x1, double x2, int nRoots);
void Clear_buffer ();

static int Compare_with_zero (double x);

enum Count_of_roots
{
    ZERO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3
};

int Compare_with_zero (double x)  // comparing coeffs with zero
{
    if (fabs(x) < EPSILON) return 0;
    else if (x < EPSILON) return -1;
    else return 1;
}

void Clear_buffer()
{
	char clear;
	do
	{
        clear = getchar();
	}

	while (clear != '\n' && clear != EOF);
}


