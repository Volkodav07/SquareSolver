# 1 "Test.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "Test.cpp"
# 1 "Test.h" 1



int Check_test (double a, double b, double c, double x2ref, double x1ref, int nRoots_ref);
int Test ();
int Testing (int test_coeff);
# 2 "Test.cpp" 2

int Testing (int test_coeff)
{
    printf("Do you want to pass the test? Press '1' to pass it, press '0' to begin solving the equation with your coeffs.\n");
    scanf("%d", &test_coeff);

    if (test_coeff == 1) { Test();}

    return 0;
}

int Check_test (double a, double b, double c, double x2ref, double x1ref, int nRoots_ref)
{
    double x1 = 0, x2 = 0;
    int nRoots = 0;

    Equation_solver(a, b, c, x1, x2, nRoots);

    if (x1 != x1ref || x2 != x2ref || nRoots != nRoots_ref)
    {
        printf("FAILED: program gives x1 = %lg, x2 = %lg, nRoots = %d. Program expected: x1 = %lg, x2 = %lg, nRoots = %d.\n", x1, x2, nRoots, x1ref, x2ref, nRoots_ref);
        return 0;
    }

    else
    {
        printf("Test is OK! Program gives the following: x1 = %lg, x2 = %lg, nRoots = %d.\n", x1ref, x2ref, nRoots_ref);
        return 1;
    }

}

int Test ()
{
    int nPassed = 0;
    nPassed += Check_test (1, -5, 6, 2, 3, TWO_ROOTS);
    nPassed += Check_test (1, -7, 12, 3, 4, TWO_ROOTS);
    nPassed += Check_test (0, 0, 0, 0, 0, INF_ROOTS);
    nPassed += Check_test (0, 2, -4, 0, 2, ONE_ROOT);
    nPassed += Check_test (1, 1, 4, 0, 0, ZERO_ROOTS);
    printf("%d DEDS of 5 POLTORASHEK. ", nPassed);

    return 0;
}
