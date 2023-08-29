#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../headers/tg_data.h"
#include "../headers/Equation_solver.h"
#include "../headers/Test.h"

int main ()  // main body
{

    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    int nRoots = 0;

    printf("Welcome to SquareSolver.\n");

    int repeating_coeff = 1;  // argument for repeating the program
    while (repeating_coeff == 1)
    {
        Get_coeffs (&a, &b, &c, &nRoots);
        printf("Your equation has the following view: %lg x*x + %lg x + lg /n", a, b, c);

        Equation_solver (a, b, c, x1, x2, nRoots); // solving equation and printing its roots
        Printing_roots (x1, x2, nRoots);

        printf("Do you want to repeat the program? Press '1' to continue, otherwise press '0' to exit the program.\n");
        scanf("%d", &repeating_coeff);

        system("cls");
    }

    int test_coeff = 0;       // argument for checking the test
    Testing (test_coeff);

    return 0;
}


