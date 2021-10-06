#include "io.h"
#include "interpret.h"

#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	// ensure we have a run method and a file to run
	if (argc != 3) 
	{
		error("Expected 3 arguments.");
	}

	size_t file_len;
	char *file_contents = load_file(argv[2], &file_len);

	printf("%s\n", argv[1]);

	if (strcmp(argv[1], "interpret") == 0)
	{
		interpret_file(file_contents);
	}
	else if (strcmp(argv[1], "compile") == 0)
	{
		error("Compilation not yet implemented.");
	}
	else
	{
		error("Unexpected run method.");
	}

	return 0;
}