#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

#include "structs.h"
#include "solvers.h"
#include "helpers.h"

enum answer_identifier solve_equation(const struct coefs *mycoefs, double *x1, double *x2)
{
    assert(x1);
    assert(x2);
    assert(x1 != x2);
    assert(isfinite(mycoefs->a));
    assert(isfinite(mycoefs->b));
    assert(isfinite(mycoefs->c));

    *x1 = 0;
    *x2 = 0;

    if(compare_doubles(mycoefs->a,0) == 0)
    {
        if(compare_doubles(mycoefs->b,0) == 0)
        {
            if(compare_doubles(mycoefs->c,0) == 0)
            {
                return INF_ROOTS;   // a == 0, b == 0, c == 0
            }
            else
            {
                return IMPOSSIBLE_EQUATION;   // a == 0, b == 0, c != 0
            }
        }
        else if(compare_doubles(mycoefs->c,0) == 0)
        {
            return ONE_ROOT;  // a == 0, b != 0, c == 0
        }
        else
        {
            solve_linear(mycoefs->b, mycoefs->c, x1);

            return ONE_ROOT;  // a == 0, b != 0, c != 0
        }
    }
    else if(compare_doubles(mycoefs->c, 0) == 0)
    {
        if(compare_doubles(mycoefs->b,0) == 0)
        {
            return ONE_ROOT;  // a != 0, b == 0, c == 0
        }
        else
        {
            solve_linear(mycoefs->a, mycoefs->b, x1); // a != 0, b != 0, c == 0

            return TWO_ROOTS;
        }
    }
    else
    {
        return solve_quadratic(mycoefs, x1, x2); // a != 0, c == 0
    }
}

enum answer_identifier solve_quadratic(const struct coefs *mycoefs, double * x1, double * x2)
{
    assert(x1);
    assert(x2);

    double discriminant = calculate_discriminant(mycoefs->a, mycoefs->b, mycoefs->c);

    if(compare_doubles(discriminant,0) == 1)
    {
        double sqofdis = sqrt(discriminant);
        *x1 = (-(mycoefs->b) + (sqofdis)) / (2 * mycoefs->a);
        *x2 = (-(mycoefs->b) - (sqofdis)) / (2 * mycoefs->a);

        return TWO_ROOTS;
    }
    else if(compare_doubles(discriminant,0) == 0)
    {
        *x1 = (-(mycoefs->b) + sqrt(discriminant)) / (2 * mycoefs->a);

        return ONE_ROOT;
    }
    else
    {
        return NO_ROOT;
    }
}

void solve_linear(double b, double c, double *x1)
{
    assert(!compare_doubles(b,0));
    assert(x1);

    *(x1) = -(c / b);
}
