#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include "solvers.h"
#include "helpers.h"

struct Equation_result solve_equation(const struct Coefs *current_coefs)

{
    assert(current_coefs);
    assert(isfinite(current_coefs->a));
    assert(isfinite(current_coefs->b));
    assert(isfinite(current_coefs->c));

    struct Equation_result result =
    {
        .x1 = NAN,
        .x2 = NAN,
        .answer_identifier = NONE
    };

    if (cmp_double(current_coefs->a,0) == 0)
    {
        if (cmp_double(current_coefs->b,0) == 0)
        {
            if (DBL_IS_ZERO(current_coefs->c))
            {
                result.answer_identifier = INF_ROOTS;

                return result;   // a == 0, b == 0, c == 0
            }
            else
            {
                result.answer_identifier = NO_ROOTS;

                return result;    // a == 0, b == 0, c != 0
            }
        }
        else if (DBL_IS_ZERO(current_coefs->c))
        {
            result.x1 = 0.0;
            result.answer_identifier = ONE_ROOT;

            return result;  // a == 0, b != 0, c == 0
        }
        else
        {
            result = solve_linear(current_coefs->b, current_coefs->c);
            result.answer_identifier = ONE_ROOT;

            return result;   // a == 0, b != 0, c != 0
        }
    }
    else if (DBL_IS_ZERO(current_coefs->c))
    {
        if (DBL_IS_ZERO(current_coefs->b))
        {
            result.x1 = 0.0;
            result.answer_identifier = ONE_ROOT;

            return result;  // a != 0, b == 0, c == 0
        }
        else
        {
            result = solve_linear(current_coefs->a, current_coefs->b); // a != 0, b != 0, c == 0
            result.x2 = 0.0;
            result.answer_identifier = TWO_ROOTS;

            return result;
        }
    }
    else
    {
        return solve_quadratic(current_coefs); // a != 0, c == 0
    }
}

struct Equation_result solve_quadratic(const struct Coefs *current_coefs)
{
    struct Equation_result quadratic_result =
    {
        .x1 = NAN,
        .x2 = NAN,
        .answer_identifier = NONE
    };

    double discriminant = calculate_discriminant(current_coefs);

    if (cmp_double(discriminant,0) == 1)
    {
        double sq_of_dis = sqrt(discriminant);
        quadratic_result.x1 = (-(current_coefs->b) + (sq_of_dis)) / (2 * current_coefs->a);
        quadratic_result.x2 = (-(current_coefs->b) - (sq_of_dis)) / (2 * current_coefs->a);
        quadratic_result.answer_identifier = TWO_ROOTS;

        return quadratic_result;
    }
    else if (DBL_IS_ZERO(discriminant))
    {
        quadratic_result.x1 = (-(current_coefs->b) + sqrt(discriminant)) / (2 * current_coefs->a);
        quadratic_result.answer_identifier = ONE_ROOT;

        return quadratic_result;
    }
    else
    {
        quadratic_result.answer_identifier = NO_ROOTS;
        return quadratic_result;
    }
}

struct Equation_result solve_linear(double b, double c)
{
    struct Equation_result linear_result =
    {
        .answer_identifier = NONE,
        .x1 = NAN,
        .x2 = NAN
    };

    if (DBL_IS_ZERO(b))
    {
        if (DBL_IS_ZERO(c))
        {
            linear_result.answer_identifier = INF_ROOTS;

            return linear_result;   //b ==0, c == 0
        }
        else
        {
            linear_result.answer_identifier = NO_ROOTS;

            return linear_result;   //b == 0, c !=0
        }
    }
    else
    {
        if (DBL_IS_ZERO(c))
        {
            linear_result.x1 = 0.0;
            linear_result.answer_identifier = ONE_ROOT;

            return linear_result;   //b !=0, c == 0
        }
        else
        {
            linear_result.x1 = -(c / b);
            linear_result.answer_identifier = ONE_ROOT;

            return linear_result;   //b != 0, c != 0
        }
    }
}

double calculate_discriminant(const struct Coefs *current_coefs)
{
    return (current_coefs->b * current_coefs->b) - (4 * current_coefs->a * current_coefs->c);
}
