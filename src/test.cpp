#include <stdio.h>
#include <math.h>
#include <string.h>

#include "test.h"
#include "helpers.h"
#include "solvers.h"

struct Test_setup
{
    struct Coefs ref_coefs;
    struct Equation_result ref_result;
    const char* test_name;
};

void quad_test(const struct Test_setup *quad_references);
void linear_test(const struct Test_setup *linear_references);

void test(char *equation_type_ID)
{
    if(!strcmp(equation_type_ID,"quad"))
    {
        const struct Test_setup quad_references[] =
        {
            {.ref_coefs = {.a = 0, .b = 0, .c =  0}, .ref_result = {.x1 =  NAN, .x2 =  NAN, .answer_identifier = INF_ROOTS}, "Infinite roots"},
            {.ref_coefs = {.a = 0, .b = 0, .c =  9}, .ref_result = {.x1 =  NAN, .x2 =  NAN, .answer_identifier =  NO_ROOTS},      "No roots1"},
            {.ref_coefs = {.a = 0, .b = 9, .c =  0}, .ref_result = {.x1 =  0.0, .x2 =  NAN, .answer_identifier =  ONE_ROOT},      "One root1"},
            {.ref_coefs = {.a = 0, .b = 5, .c = 10}, .ref_result = {.x1 = -2.0, .x2 =  NAN, .answer_identifier =  ONE_ROOT},      "One root2"},
            {.ref_coefs = {.a = 9, .b = 0, .c =  0}, .ref_result = {.x1 =  0.0, .x2 =  NAN, .answer_identifier =  ONE_ROOT},      "One root3"},
            {.ref_coefs = {.a = 3, .b = 9, .c =  0}, .ref_result = {.x1 = -3.0, .x2 =  0.0, .answer_identifier = TWO_ROOTS},     "Two roots1"},
            {.ref_coefs = {.a = 2, .b = 9, .c =  7}, .ref_result = {.x1 = -1.0, .x2 = -3.5, .answer_identifier = TWO_ROOTS},     "Two roots2"},
            {.ref_coefs = {.a = 1, .b = 4, .c =  4}, .ref_result = {.x1 = -2.0, .x2 =  NAN, .answer_identifier =  ONE_ROOT},      "One root4"},
            {.ref_coefs = {.a = 1, .b = 1, .c =  1}, .ref_result = {.x1 =  NAN, .x2 =  NAN, .answer_identifier =  NO_ROOTS},      "No roots2"}
        };

        for (int test_id = 0; test_id < 9; test_id++)
        {
            quad_test(&quad_references[test_id]);
        }
    }
    else if (!strcmp(equation_type_ID,"linear"))
    {
        const struct Test_setup linear_references[] =
        {
            {.ref_coefs = {.a = 0, .b = 0, .c =  NAN}, .ref_result = {.x1 =  NAN, .x2 =  NAN, .answer_identifier = INF_ROOTS}, "Infinite roots"},
            {.ref_coefs = {.a = 1, .b = 0, .c =  NAN}, .ref_result = {.x1 =  0.0, .x2 =  NAN, .answer_identifier =  ONE_ROOT},      "One root1"},
            {.ref_coefs = {.a = 0, .b = 1, .c =  NAN}, .ref_result = {.x1 =  NAN, .x2 =  NAN, .answer_identifier =  NO_ROOTS},      "No roots"},
            {.ref_coefs = {.a = 3, .b = 9, .c = NAN}, .ref_result = {.x1 = -3.0, .x2 =  NAN, .answer_identifier =  ONE_ROOT},      "One root2"},
        };

        for (size_t test_id = 0; test_id < sizeof(linear_references) / sizeof(Test_setup); test_id++)
        {
            linear_test(&linear_references[test_id]);
        }
    }
    else
    {
        printf("No such argument value option for argv[2].\n");
    }
}

void quad_test(const struct Test_setup *quad_references)
{
    struct Equation_result test_result =
    {
        .x1 = NAN,
        .x2 = NAN,
        .answer_identifier = NONE
    };

    struct Coefs mycoefs =
    {
        quad_references->ref_coefs.a,
        quad_references->ref_coefs.b,
        quad_references->ref_coefs.c
    };

    test_result = solve_equation(&mycoefs);

    if (((cmp_double(test_result.x1,quad_references->ref_result.x1) == 0) &&
         (cmp_double(test_result.x2,quad_references->ref_result.x2) == 0)&&
         (test_result.answer_identifier == (quad_references->ref_result.answer_identifier))))
    {
        printf("%s test succeded\n",quad_references->test_name);
    }
    else
    {
        printf("%s test failed\n",quad_references->test_name);
        printf("x1 = %lf, x2 = %lf, answer_identifier = %d\nref_x1 = %lf, ref_x2 = %lf, "
               "ref_answer_identifier = %d\n", test_result.x1, test_result.x2,
                                               test_result.answer_identifier,
                                               quad_references->ref_result.x1, quad_references->ref_result.x2,
                                               quad_references->ref_result.answer_identifier);
    }
}

void linear_test(const struct Test_setup *linear_references)
{
    struct Equation_result test_result =
    {
        .x1 = NAN,
        .x2 = NAN,
        .answer_identifier = NONE
    };

    double a = linear_references->ref_coefs.a;
    double b = linear_references->ref_coefs.b;

    test_result = solve_linear(a, b);

    if (((cmp_double(test_result.x1,linear_references->ref_result.x1) == 0) &&
         (test_result.answer_identifier == (linear_references->ref_result.answer_identifier))))
    {
        printf("%s test succeded\n",linear_references->test_name);
    }
    else
    {
        printf("%s test failed\n",linear_references->test_name);
        printf("x = %lf, answer_identifier = %d\nref_x = %lf,"
               "ref_answer_identifier = %d\n", test_result.x1,
                                               test_result.answer_identifier,
                                               linear_references->ref_result.x1,
                                               linear_references->ref_result.answer_identifier);
    }

}
