# 1 "equation_solver.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "equation_solver.cpp"
# 1 "equation_solver.h" 1



int Linear_solver (const double b, const double c, double *x1, int *nRoots);
int Square_solver (const double a, const double b, const double c, double *x1, double *x2, int *nRoots);
int Equation_solver (double a, double b, double c, double &x1, double &x2, int &nRoots);
# 2 "equation_solver.cpp" 2

int Linear_solver (const double b, const double c, double *x1, int *nRoots)
{
     if (Compare_with_zero(b) == 0)
     {
        if (Compare_with_zero(c) == 0)
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

     return 0;
}

int Square_solver (const double a, const double b, const double c, double *x1, double *x2, int *nRoots)
{
    double D = b*b - 4*a*c;

    if (Compare_with_zero (D) == -1)
    {
        *nRoots = ZERO_ROOTS;
    }

    double sqrt_D = sqrt (D);

    if (Compare_with_zero (D) == 0)
    {
        *x1 = -b / (2*a);
        *nRoots = ONE_ROOT;
    }

    if (Compare_with_zero (D) == 1)
    {
        *x1 = (-b + sqrt_D) / (2*a);
        *x2 = (-b - sqrt_D) / (2*a);
        *nRoots = TWO_ROOTS;
    }

    return 0;
}

int Equation_solver (double a, double b, double c, double &x1, double &x2, double &nRoots)
{
    if (Compare_with_zero (a) == 0) {Linear_solver (b, c, &x1, &nRoots);}
    else {Square_solver (a, b, c, &x1, &x2, &nRoots);}

    return 0;
}
