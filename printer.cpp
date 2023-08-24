#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

#include "structs.h"
#include "printer.h"
#include "helpers.h"

void print_answer(int answer_identifier, double x1, double x2)
{
    switch(answer_identifier)
    {
        case TWO_ROOTS: printf("x1 = %.6lf\n",x1);
                printf("x2 = %.6lf\n",x2);
                break;
        case ONE_ROOT: printf("x = %.6lf\n",x1);
                break;
        case NO_ROOT: printf("No root.\n");
                break;
        case IMPOSSIBLE_EQUATION: printf("The equation with such coefficients is impossible.\n");
                break;
        case INF_ROOTS:
                printf("The equation has infinit roots.\n");
                break;
        default:
                printf("ERROR:\n");
                printf("answer_identifier value is weird.\n");
    }
}
