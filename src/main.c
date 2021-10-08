#include "io.h"
#include "interpret.h"

#include <string.h>
#include <stdio.h>

#define INTERPRET_STR "-i"
#define COMPILE_STR   "-c"

int main(int argc, char const *argv[])
{
	// ensure we have a run method and a file to run
	if (argc != 3) error("Expected 3 arguments.");

	// open the file to pass it to compilation and interpreting
	FILE *file = open_file(argv[2]);

	if (strcmp(argv[1], INTERPRET_STR) == 0) interpret_file(file);
	else if (strcmp(argv[1], COMPILE_STR) == 0) error("Compilation not yet implemented.");
	else error("Unexpected run method.");

	return 0;
}