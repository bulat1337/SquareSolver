#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

#include "readers.h"
// #include "solvers.h"


// #include "helpers.h"
// #include "structs.h"

void read_coefs_stdin(struct coefs *mycoefs)
{
    printf("To solve a solve_quadratic equation enter coefficient a:");
    read_coef(&(mycoefs->a));

    printf("coefficient b:");
    read_coef(&(mycoefs->b));

    printf("and coefficient c:");
    read_coef(&(mycoefs->c));
}

void read_coef(double *coef)
{
    assert(coef);

    bool flag = false;
    while(flag == false)
    {
        while(scanf("%lf", coef) != true)
        {
            printf("Coefitient must be number.\n");
            printf("Try again:");
            clear_buffer();
        }
        if(isspace(getchar()))
        {
            flag = true;
        }
        else
        {
            printf("Coefitient must be number.\n");
            printf("Try again:");
            clear_buffer();
        }
    }
}
