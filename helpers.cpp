#include <stdio.h>
#include <math.h>

#include "helpers.h"

double calculate_discriminant(double a, double b, double c)
{
    double s_discriminant = (b * b) - (4 * a * c);

    return s_discriminant;
}

int compare_doubles(double first_double, double second_double)
{
    double eps = 1e-7;
    if (fabs(first_double - second_double) < eps)
    {
        return 0;
    }
    else if ((first_double - second_double) > eps)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void clear_buffer(void)
{
    while(getchar() != '\n');
}
