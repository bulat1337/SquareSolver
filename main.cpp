#include <stdio.h>
#include <math.h>

#include "structs.h"
#include "readers.h"
#include "solvers.h"
#include "printer.h"
#include "testers.h"

int main() {
    double x1 = NAN, x2 = NAN;
    int answer_identifier = TWO_ROOTS; // todo NONE
    char ans = 'n';
    struct coefs mycoefs =
    {
        NAN,
        NAN, // todo use .field
        NAN
    };

    // struct Foo {
    //     int a;
    //     int b;
    // };
//
//     struct Foo bar1 = {.a = 10, .b = 20};
//     struct Foo bar2 = {.b = 10, .a = 20};
//     struct Foo bar3 = {30, 40};

    test();

    // 1) print_user_promt (static int solveCount = 0;)
    // 2) read answer => ...

    printf("Hi! U wanna solve a solve_quadratic equation?(enter 'y' if u do):");

    while ((ans = getchar()) == 'y')
    {
        read_coefs_stdin(&mycoefs);
        answer_identifier = solve_equation(&mycoefs, &x1, &x2);
        print_answer(answer_identifier, x1, x2);

        printf("U wanna solve another?\n");

    }
    printf("Thats it! Bye!");

    return 0;
}

