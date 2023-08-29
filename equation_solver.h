#ifndef EQUATION_SOLVER_H_
#define EQUATION_SOLVER_H_

int Linear_solver (const double b, const double c, double *x1, int *nRoots);
int Square_solver (const double a, const double b, const double c, double *x1, double *x2, int *nRoots);
int Equation_solver (double a, double b, double c, double &x1, double &x2, int &nRoots);

#endif
