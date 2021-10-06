#include "interpret.h"

#include <string.h>

void interpret_line(char *line)
{
	//do they need comments?
    //if (line[0] == '/' && line[1] == '/') return 0;
    
    char *remaining = NULL, *word = NULL;
    word = strtok_r(line, " ", &remaining);
    
    while (word != NULL)
    {
        if (strlen(word) == 0) continue;

        //TODO: put code for interpreting lines here
   
        word = strtok_r(remaining, " ", &remaining);
    }
}

void interpret_file(char *file_contents)
{
	char *line = NULL;
    line = strtok(file_contents, "\r\n");
    
    while (line != NULL)
    {
        // not having a new line at the end of the file causes problems
        // removing the strange backspace at the end fixes that
        char *backspace = strchr(line, 8);
        if (backspace != NULL) *backspace = 0;

        interpret_line(line);

        line = strtok(NULL, "\r\n");
    }
}