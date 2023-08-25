#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 1e-9
#define MAX_DOUBLE 1.7E+308

static int compare_with_zero (double x);

enum count_of_roots
{
    ZERO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3
};

int get_coeffs (double *a, double *b, double *c, int *nRoots);
int Linear_Solver (const double b, const double c, double *x1, int *nRoots);
int Square_Solver (const double a, const double b, const double c, double *x1, double *x2, int *nRoots);
int cases (double x1, double x2, int nRoots);
void Clear_Buffer ();

