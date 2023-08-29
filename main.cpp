#include "header.h"

int main ()  // main body
{

    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    int nRoots = 0;

    printf("Welcome to SquareSolver.\n");

    int repeating_coeff = 1;  // argument for repeating the program
    while (repeating_coeff == 1)
    {
        Get_coeffs (&a, &b, &c, &nRoots);
        /*printf("Your equation has following view: %d x*x + %d x +c /n", a, b, c);*/

        Equation_solver (a, b, c, x1, x2, nRoots);

        Printing_roots (x1, x2, nRoots);

        printf("Do you want to repeat the program? Press '1' to continue, otherwise press '0' to exit the program.\n");
        scanf("%d", &repeating_coeff);

        system("cls");
    }

    int test_coeff = 0;       // argument for checking the test
    Testing (test_coeff);

    return 0;
}

int Get_coeffs (double *a_ptr, double *b_ptr, double *c_ptr, int *nRoots)  // taking coeffs from user
{
    printf("Enter a, b and c with space within: \n" );

    while (scanf("%lg %lg %lg", a_ptr, b_ptr, c_ptr) != 3 || isfinite (*a_ptr) == 0 || isfinite (*b_ptr) == 0 || isfinite (*c_ptr) == 0)
    {
        printf("Invalid input. Enter new coeffs: \n");
        Clear_buffer();
    }

    system("cls");

    return 0;
}

int Printing_roots (double x1, double x2, int nRoots)
{
    switch(nRoots)
    {
        case ZERO_ROOTS: {printf("No roots.\n");}
        break;

        case ONE_ROOT: {printf("There is one root x1 = %lg\n", x1);}
        break;

        case TWO_ROOTS: {printf("There are two roots x1 = %lg, x2 = %lg\n", x1, x2);}
        break;

        case INF_ROOTS: {printf("There is infinite count of roots.\n");}
        break;

    }

    return 0;
}


