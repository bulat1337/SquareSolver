#ifndef SOLVERS_H
#define SOLVERS_H

struct Coefs
{
    double a;
    double b;
    double c;
};

enum Answer_identifier
{
    NONE = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 8,
};

struct Equation_result
{
    double x1;
    double x2;
    enum Answer_identifier answer_identifier;
};


struct Equation_result solve_equation(const struct Coefs *mycoefs);
struct Equation_result solve_quadratic(const struct Coefs *mycoefs);
struct Equation_result solve_linear(const double b, const double c);
double calculate_discriminant(const double a, const double b, const double c);

#endif
