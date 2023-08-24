#include <stdio.h>
#include <math.h>



#include "structs.h"
#include "readers.h"
#include "solvers.h"
#include "printer.h"




int main()
{
    double x1 = NAN, x2 = NAN;
    int answer_identifier = TWO_ROOTS;
    char ans = 'n';
    struct coefs mycoefs =
    {
        NAN,
        NAN,
        NAN
    };

    printf("Hi! U wanna solve a solve_quadratic equation?(enter \"y\" if u do):");
    while((ans = getchar()) == 'y')
    {
        read_coefs_stdin(&mycoefs);
        answer_identifier = solve_equation(&mycoefs, &x1, &x2);
        print_answer(answer_identifier, x1, x2);


        printf("U wanna solve another?\n");

    }
    printf("Thats it! Bye!");

    return 0;
}

