#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#include "readers.h"
#include "solvers.h"
#include "printer.h"
#include "test.h"

int main(int, char *argv[])
{
    char ans = 'n';

    struct Equation_result myresult =
    {
        .x1 = NAN,
        .x2 = NAN,
        .answer_identifier = NONE
    };

    struct Coefs mycoefs =
    {
        .a = NAN,
        .b = NAN,
        .c = NAN
    };

    assert(argv[1]);
    assert(argv[2]);

    if(!strcmp(argv[1],"test"))
    {
        test(argv[2]);
    }
    else if(!strcmp(argv[1],"std"))
    {
        if(!strcmp(argv[2],"quad"))
        {
            printf("Hi! U wanna solve a quadratic equation?(enter 'y' if u do):");
            while ((ans = (char)getchar()) == 'y')
            {
                read_coefs_stdin(&mycoefs, argv[2]);
                myresult = solve_equation(&mycoefs);
                print_answer(myresult.answer_identifier, myresult.x1, myresult.x2);

                printf("U wanna solve another?\n");

            }
            printf("Thats it! Bye!");
        }
        else if(!strcmp(argv[2],"linear"))
        {
            printf("Hi! U wanna solve a linear equation?(enter 'y' if u do):");
            while ((ans = (char)getchar()) == 'y')
            {
                read_coefs_stdin(&mycoefs, argv[2]);
                myresult = solve_linear(mycoefs.a, mycoefs.b);
                print_answer(myresult.answer_identifier, myresult.x1, myresult.x2);

                printf("U wanna solve another?\n");

            }
            printf("Thats it! Bye!");
        }
    }
    else
    {
        printf("No such argument value option for argv[1].\n");
    }

    return 0;
}

