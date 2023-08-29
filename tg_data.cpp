#include <tg_data.h>

int Get_coeffs (double *a_ptr, double *b_ptr, double *c_ptr, int *nRoots)  // taking coeffs from user
{
    printf("Enter a, b and c with space within: \n" );

    while (scanf("%lg %lg %lg", a_ptr, b_ptr, c_ptr) != 3 || isfinite (*a_ptr) == 0 || isfinite (*b_ptr) == 0 || isfinite (*c_ptr) == 0 || Space_invalid())
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

int Space_invalid (void)
{
    int ch = (char)0;
    while((ch = getchar()) != '\n')
      {
        if (!isspace(ch))
          return YES;
      }
    return NO;
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
