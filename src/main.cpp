#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#include "readers.h"
#include "solvers.h"
#include "printer.h"
#include "test.h"
#include "cmd_line_parsing.h"
#include "cmd_line_arg_based_actions.h"

int main(const int argc, char *argv[])
{
    struct Flag_IDs square_solver_IDs =
    {
        .test_ID = 0,
        .equation_type_ID = 0,
		.test_type_ID = 0,
		.help_ID = 1
    };

	square_solver_IDs = cmd_line_parser(argc, argv);

	action_according_to_cmd(square_solver_IDs);

    return 0;
}

