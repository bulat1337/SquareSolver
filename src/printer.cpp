#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

#include "printer.h"

int print_answer(enum Answer_identifier answer_identifier, double x1, double x2)
{
    switch(answer_identifier)
    {
        case TWO_ROOTS:
        {
            printf("x1 = %.6lf\n",x1);
            printf("x2 = %.6lf\n",x2);
            return 0;
            break;
        }
        case ONE_ROOT:
        {
            printf("x = %.6lf\n",x1);
            return 0;
            break;
        }
        case NO_ROOTS:
        {
            printf("No root.\n");
            return 0;
            break;
        }
        case INF_ROOTS:
        {
            printf("The equation has infinite roots.\n");
            return 0;
            break;
        }
        case NONE:
        {
            return -1;
            break;
        }
        default:
        {
            return -1;
        }
    }
}
