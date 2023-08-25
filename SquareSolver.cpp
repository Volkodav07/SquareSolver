#include "header.h" // adding packages

int main ()  // main body
{
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;
    double a_ptr = NAN, b_ptr = NAN, c_ptr = NAN;
    int nRoots = 0;

    get_coeffs (&a, &b, &c, &nRoots);

    if (compare_with_zero (a) == 0) Linear_Solver (b, c, &x1, &nRoots);
    else Square_Solver (a, b, c, &x1, &x2, &nRoots);

    cases (x1, x2, nRoots);

    return 0;
}

int compare_with_zero (double x)  // comparing coeffs with zero
{
    if (fabs(x) < EPSILON) return 0;
    else if (x < EPSILON) return -1;
    else return 1;
}

int get_coeffs (double *a_ptr, double *b_ptr, double *c_ptr, int *nRoots)  // taking coeffs from user
{
    printf("Welcome to SquareSolver. Enter a, b and c with space within: \n" );

    while (scanf("%lg %lg %lg", a_ptr, b_ptr, c_ptr) != 3)
    {
        printf("Invalid input. Enter new coeffs in right type: \n");
        Clear_Buffer();
    }

    while ((fabs(*a_ptr) > MAX_DOUBLE) || (fabs(*b_ptr) > MAX_DOUBLE) || (fabs(*c_ptr) > MAX_DOUBLE))
    {
        printf("Invalid input. Enter new coeffs less than 1.7E+308: \n");
        Clear_Buffer();
    }
}

int Linear_Solver (const double b, const double c, double *x1, int *nRoots) // solving LinearSolver (a = 0, b != 0, c = 0)
{
     if (compare_with_zero (b) == 0)
     {
        if (compare_with_zero (c) == 0)
        {
            *nRoots = INF_ROOTS;
        }

        else
        {
            *nRoots = ZERO_ROOTS;
        }
     }

     else
     {
        *x1 = -c / b;
        *nRoots = ONE_ROOT;
     }
}

int Square_Solver (const double a, const double b, const double c, double *x1, double *x2, int *nRoots)
{
    double D = b*b - 4*a*c;

    if (compare_with_zero (D) == -1)
    {
        *nRoots = ZERO_ROOTS;
    }

    double sqrt_D = sqrt (D);

    if (compare_with_zero (D) == 0)
    {
        *x1 = *x2 = -b / (2*a);
        *nRoots = ONE_ROOT;
    }

    if (compare_with_zero (D) == 1)
    {
        *x1 = (-b + sqrt_D) / (2*a);
        *x2 = (-b - sqrt_D) / (2*a);
        *nRoots = TWO_ROOTS;
    }
}

int cases (double x1, double x2, int nRoots)
{
    switch(nRoots)
    {
        case ZERO_ROOTS: {printf("No roots.");}
        break;

        case ONE_ROOT: {printf("There is one root x1 = %lg", x1);}
        break;

        case TWO_ROOTS: {printf("There are two roots x1 = %lg, x2 = %lg", x1, x2);}
        break;

        case INF_ROOTS: {printf("There is infinite count of roots.");}
        break;
    }
}

void Clear_Buffer()
{
	char clear;
	do
	{
        clear = getchar();
	}

	while (clear != '\n' && clear != EOF);
}
