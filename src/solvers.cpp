#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include "solvers.h"
#include "helpers.h"

#define DBL_IS_ZERO(d_arg) (bool)(cmp_double(d_arg,0) == 0)

struct Equation_result solve_equation(const struct Coefs *mycoefs)

{
    assert(mycoefs);
    assert(isfinite(mycoefs->a));
    assert(isfinite(mycoefs->b));
    assert(isfinite(mycoefs->c));

    struct Equation_result my_equation_result =
    {
        .x1 = NAN,
        .x2 = NAN,
        .answer_identifier = NONE
    };

    if (cmp_double(mycoefs->a,0) == 0)
    {
        if (cmp_double(mycoefs->b,0) == 0)
        {
            if (DBL_IS_ZERO(mycoefs->c))
            {
                my_equation_result.answer_identifier = INF_ROOTS;

                return my_equation_result;   // a == 0, b == 0, c == 0
            }
            else
            {
                my_equation_result.answer_identifier = NO_ROOTS;

                return my_equation_result;    // a == 0, b == 0, c != 0
            }
        }
        else if(DBL_IS_ZERO(mycoefs->c))
        {
            my_equation_result.x1 = 0.0;
            my_equation_result.answer_identifier = ONE_ROOT;

            return my_equation_result;  // a == 0, b != 0, c == 0
        }
        else
        {
            my_equation_result = solve_linear(mycoefs->b, mycoefs->c);
            my_equation_result.answer_identifier = ONE_ROOT;

            return my_equation_result;   // a == 0, b != 0, c != 0
        }
    }
    else if(DBL_IS_ZERO(mycoefs->c))
    {
        if(DBL_IS_ZERO(mycoefs->b))
        {
            my_equation_result.x1 = 0.0;
            my_equation_result.answer_identifier = ONE_ROOT;

            return my_equation_result;  // a != 0, b == 0, c == 0
        }
        else
        {
            my_equation_result = solve_linear(mycoefs->a, mycoefs->b); // a != 0, b != 0, c == 0
            my_equation_result.x2 = 0.0;
            my_equation_result.answer_identifier = TWO_ROOTS;

            return my_equation_result;
        }
    }
    else
    {
        return solve_quadratic(mycoefs); // a != 0, c == 0
    }
}

struct Equation_result solve_quadratic(const struct Coefs *mycoefs)
{
    struct Equation_result quadratic_result =
    {
        .x1 = NAN,
        .x2 = NAN,
        .answer_identifier = NONE
    };

    double discriminant = calculate_discriminant(mycoefs->a, mycoefs->b, mycoefs->c);

    if (cmp_double(discriminant,0) == 1)
    {
        double sq_of_dis = sqrt(discriminant);
        quadratic_result.x1 = (-(mycoefs->b) + (sq_of_dis)) / (2 * mycoefs->a);
        quadratic_result.x2 = (-(mycoefs->b) - (sq_of_dis)) / (2 * mycoefs->a);
        quadratic_result.answer_identifier = TWO_ROOTS;

        return quadratic_result;
    }
    else if (DBL_IS_ZERO(discriminant))
    {
        quadratic_result.x1 = (-(mycoefs->b) + sqrt(discriminant)) / (2 * mycoefs->a);
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

    if(DBL_IS_ZERO(b))
    {
        if(DBL_IS_ZERO(c))
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
        if(DBL_IS_ZERO(c))
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

double calculate_discriminant(double a, double b, double c)
{
    return (b * b) - (4 * a * c);
}
