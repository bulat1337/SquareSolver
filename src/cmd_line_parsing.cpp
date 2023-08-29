#include <unistd.h>
#include <string.h>

#include "cmd_line_parsing.h"

struct Flag_IDs cmd_line_parser(const int argc, char *argv[])
{
	struct Flag_IDs square_solver_IDs =
    {
        .test_ID = 0,
        .equation_type_ID = 0,
		.test_type_ID = 0,
		.help_ID = 1
    };

	int getopt_output;
	opterr = 0;

	while((getopt_output = getopt(argc, argv, "qlht:")) != -1)
	{
		switch(getopt_output)
		{
			case 'h':
			{
				square_solver_IDs.help_ID = 1;
				break;
			}
			case 't':
			{
				square_solver_IDs.test_ID = 1;
				square_solver_IDs.help_ID = 0;

				if(!strcmp(optarg, "q"))
				{
					square_solver_IDs.test_type_ID = 'q';
				}
				else if(!strcmp(optarg, "l"))
				{
					square_solver_IDs.test_type_ID = 'l';
				}
				else
				{
					square_solver_IDs.help_ID = 1;
				}
				break;
			}
			case 'q':
			{
				square_solver_IDs.equation_type_ID = 'q';
				square_solver_IDs.help_ID = 0;
				break;
			}
			case 'l':
			{
				square_solver_IDs.equation_type_ID = 'l';
				square_solver_IDs.help_ID = 0;
				break;
			}
			default:
			{
				square_solver_IDs.help_ID = 1;
				break;
			}
		}
	}

	return square_solver_IDs;
}
