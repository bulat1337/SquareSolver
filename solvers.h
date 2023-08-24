#ifndef SOLVERS_H
#define SOLVERS_H

enum answer_identifier solve_equation(const struct coefs *mycoefs, double *x1, double *x2);
enum answer_identifier solve_quadratic(const struct coefs *mycoefs, double *x1, double *x2);
void solve_linear(const double b, const double c, double *x1);

#endif
