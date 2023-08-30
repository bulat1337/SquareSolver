#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

#include "readers.h"
#include "helpers.h"

void read_coefs_stdin(struct Coefs *current_coefs, int equation_type_ID)
{
    printf("Enter coefficient a:");
    read_coef(stdin, &(current_coefs->a));

    printf("coefficient b:");
    read_coef(stdin, &(current_coefs->b));

    if (equation_type_ID == 'q')
    {
        printf("and coefficient c:");
        read_coef(stdin, &(current_coefs->c));
    }
}

void read_coef(FILE* input_src, double *coef)
{
    assert(coef);

    while (true)
    {
        while(fscanf(input_src, "%lf", coef) != true)
        {
            fprintf(stderr,"Coefitient must be a single number.\n");
            fprintf(stderr,"Try again:");

            clear_buffer();
        }

        char next_sym = 0;
        if (fscanf(input_src, "%c", &next_sym) != 1 || next_sym != '\n')
        {
            fprintf(stderr,"Coefitient must be a single number.\n");
            fprintf(stderr,"Try again:");
			
            clear_buffer();
        }
        else
        {
            break;
        }
    }
}
