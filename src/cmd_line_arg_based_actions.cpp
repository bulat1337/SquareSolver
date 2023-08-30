#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#include "readers.h"
#include "solvers.h"
#include "printer.h"
#include "test.h"
#include "cmd_line_arg_based_actions.h"

void action_according_to_cmd(struct Flag_IDs square_solver_IDs)
{
	char ans = 'n';

    struct Equation_result current_result =
    {
        .x1 = NAN,
        .x2 = NAN,
        .answer_identifier = NONE
    };

    struct Coefs current_coefs =
    {
        .a = NAN,
        .b = NAN,
        .c = NAN
    };

	if(square_solver_IDs.help_ID == 1)
	{
		printf("flags:\n");
		printf("-h: get help\n");
		printf("-t: run testers\n");
		printf("    values:\n");
		printf("    q to run quadratic tests:\n");
		printf("    l to run linear tests:\n");

		printf("-q: to solve quadratic equation\n");
		printf("-l: to solve quadratic equation\n");

		exit(0);
	}

	if(square_solver_IDs.test_ID == 1)
	{
		if(square_solver_IDs.test_type_ID == 'q')
		{
			test('q');
		}
		else if(square_solver_IDs.test_type_ID == 'l')
		{
			test('l');
		}
	}

	if(square_solver_IDs.equation_type_ID != 0)
	{
		printf("Hi! U wanna solve an equation?(enter 'y' if u do):");
		while ((ans = (char)getchar()) == 'y')
		{
			read_coefs_stdin(&current_coefs, square_solver_IDs.equation_type_ID);
			if(square_solver_IDs.equation_type_ID == 'q')
			{
				current_result = solve_equation(&current_coefs);
			}
			else
			{
				current_result = solve_linear(current_coefs.a, current_coefs.b);
			}

			int res = print_answer(current_result.answer_identifier, current_result.x1, current_result.x2);
			if (res == -1)
			{
				fprintf(stderr, "ERROR:\n");
				fprintf(stderr, "answer_identifier value is invalid.\n");
			}

			printf("U wanna solve another?\n");
		}
		printf("Thats it! Bye!");
	}
}
