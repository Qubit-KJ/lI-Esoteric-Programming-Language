#include "runargs.h"
#include "io.h"

#include <string.h>

RUN_FLAG arg_runmode = 0;
char const *arg_filepath = NULL;

void check_option(char const *option)
{
	if (strcmp(option, INTERPRET_FLAG) == 0)
	{
		arg_runmode = RF_MODE_INTERPRET;
		return;
	}
	if (strcmp(option, COMPILE_FLAG) == 0)
	{
		arg_runmode = RF_MODE_COMPILE;
		return;
	}
}

void check_other(char const *other)
{
	// get filepath first.
	if (arg_filepath == NULL) { arg_filepath = other; } return;
}

void set_run_args(int argc, char const *argv[])
{
	for (size_t arg = 1; arg < argc; arg++)
	{
		if (argv[arg][0] == '-') check_option(argv[arg]);
		else check_other(argv[arg]);
	}
}

void check_run_args(void)
{
	if (arg_filepath == NULL) error("No input file provided.");
	if (arg_runmode == 0) error("No valid run method provided.");
}
