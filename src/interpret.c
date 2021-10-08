#include "interpret.h"

#include <string.h>
#include <stdio.h>

size_t line_n = 0;

void interpret_line(char *line)
{
    // for comments
    if (line[0] == '/' && line[1] == '/') return;
    
    char *remaining = NULL, *word = NULL;
    word = strtok_r(line, " ", &remaining);
    
    while (word != NULL)
    {
        if (strlen(word) == 0) continue;

        //TODO: put code for interpreting lines here
   
        word = strtok_r(remaining, " ", &remaining);
    }
}

void interpret_file(FILE *file)
{
    char line[MAX_LINE_LEN]; 
    while(fgets(line, MAX_LINE_LEN, file) != NULL) {
        line_n ++;
        interpret_line(line);
    }
    fclose(file);
    printf("%lu\n", line_n);
}




