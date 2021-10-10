#include "io.h"
#include "interpret.h"
#include "runargs.h"

#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	set_run_args(argc, argv);
	check_run_args();

	// open the file to pass it to compilation and interpreting
	FILE *file = open_file(arg_filepath);

	if (arg_runmode == RF_MODE_INTERPRET) interpret_file(file);
	else if (arg_runmode == RF_MODE_COMPILE) error("Compilation not yet implemented.");

	return 0;
}