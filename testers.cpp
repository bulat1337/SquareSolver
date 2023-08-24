// testers.cpp -> test.cpp

#include <stdio.h>
#include <math.h>

#include "testers.h"
#include "structs.h"
#include "helpers.h"

#include "solvers.h"

struct test_setup // todo naming Capital
{
    double a; // todo coeffs
    double b;
    double c;
    double x1;
    double x2;
    int answer_identifier;
    const char* test_name;
};

// todo codestyle (choose)
// snake_style
// otherStyle

void TestOne(const struct test_setup *references);

void test(void)
{
    int i; //  1) unit
            // 2) name
            // 3) hernya

    struct test_setup references[] =
    {
        // {.coeffs = {.a = 10, .b = 20, .c=30
        {.a = 0, .b = 0, .c = 0, .x1 = NAN, .x2 = NAN, .answer_identifier = INF_ROOTS, "Infinite roots"},
        {.a = 0, .b = 0, .c = 9, .x1 = NAN, .x2 = NAN, .answer_identifier = IMPOSSIBLE_EQUATION, "Impossible equation"}
    };

    printf("Do you wanna run the tester?(enter 'y' if you do)");

    if ((int) getchar() == 'y')
    {
        for (int i = 0; i < 2; i++) // test_number / test_num / test_id / idx
        {
            TestOne(&references[i]);
        }
    }
    else
    {
        printf("ok then\n");
    }

    clear_buffer();


}

void TestOne(const struct test_setup *references)
{
    double x1 = NAN, x2 = NAN;
    int answer_identifier = TWO_ROOTS;
    struct coefs mycoefs =
    {
        references->a,
        references->b,
        references->c
    };

    answer_identifier = solve_equation(&references->coefs, &x1, &x2);

    if ((compare_doubles(x1,references->x1)
    && compare_doubles(x2,references->x2)
    && (answer_identifier == (references->answer_identifier))))
    {
        printf("%s test succeded\n",references->test_name);
    }
    else
    {
        printf("%s test failed\n",references->test_name);
        printf("x1 = %lf, x1 = %lf, answer_identifier = %d\nref_x1 = %lf, ref_x2 = %lf, "
               "ref_answer_identifier = %d\n", x1, x2,
                                               answer_identifier,
                                               references->x1, references->x2,
                                               references->answer_identifier);
    }
}
