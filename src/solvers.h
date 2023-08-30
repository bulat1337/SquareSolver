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

/// @brief This function solves an equation.
/// It uses solve_quadratic() ans solve_linear() to solve particular type of equation.
/// @param current_coefs struct of coeffs that will be used to solve th equation.
/// @return Equation_result struct of the results of the equation.
struct Equation_result solve_equation(const struct Coefs *current_coefs);

/// @brief This function solves a quadratic equation.
/// @param current_coefs struct of coeffs that will be used to solve th equation.
/// @return Equation_result struct of the results of the equation.
struct Equation_result solve_quadratic(const struct Coefs *current_coefs);

/// @brief This function solves a linear equation.
/// @param b first coefficient of the linear equation.
/// @param c second coefficient of the linear equation.
/// @return Equation_result struct of the results of the equation.
struct Equation_result solve_linear(const double b, const double c);

/// @brief This fuction calculates fiscriminant.
/// @param current_coefs struct of coeffs that will be used to solve th equation.
/// @return The value of calculated discriminant.
double calculate_discriminant(const struct Coefs *current_coefs);

#endif
