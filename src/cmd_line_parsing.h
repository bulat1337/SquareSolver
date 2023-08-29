#ifndef CMD_LINE_PARSING
#define CMD_LINE_PARSING

struct Flag_IDs
{
	int test_ID;
	int equation_type_ID;
	int test_type_ID;
	int help_ID;
};

/// @brief This function parses cmd line arguments.
/// @param argc cmd line argument counter.
/// @param argv array of pointers to cmd line arguments.
struct Flag_IDs cmd_line_parser(const int argc, char *argv[]);

#endif
