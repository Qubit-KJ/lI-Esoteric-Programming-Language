#include "io.h"

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

char *load_file(char const *path, size_t *len)
{
    FILE *file = fopen(path, "r");

    if (!file)
    {
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    *len = ftell(file);
    rewind(file);

    char *contents = malloc(*len + 1);

    if (!contents)
    {
        fclose(file);
        free(contents);
        exit(1);
    }

    if( 1 != fread( contents , *len, 1 , file) )
    {
        fclose(file);
        free(contents);
        exit(1);
    }
    
    char *fixed_contents = calloc(sizeof(char), *len);
    strncpy(fixed_contents, contents, *len);
    free(contents);

    fclose(file);
    return fixed_contents;
}

/* 
    routine for printing a character to Il output
    code modified from: 
        https://www.programmingsimplified.com/c/source-code/c-program-convert-decimal-to-binary
*/
void printchril(char chr)
{
    for (int c = 8 - 1; c >= 0; c--)
    {
        write(STDOUT_FILENO, (chr >> c) & 1 ? "I" : "l", 1);
    }
}

// routine for printing a string to Il output.
void printstril(char *str)
{
    for (char *c = str; *c != '\0'; c++)
    {
        printchril(*c);
    }
}
