#include "io.h"
#include "interpret.h"

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *load_file(char const *path, size_t *len)
{
    FILE *file = fopen(path, "r");

    if (!file)
    {
        error("IO", "Error opening file '%s'.", path);
    }

    fseek(file, 0, SEEK_END);
    *len = ftell(file);
    rewind(file);

    char *contents = malloc(*len + 1);

    if (!contents)
    {
        fclose(file);
        free(contents);
        error("IO", "Error allocating memory for file '%s'.", path);
    }

    if( 1 != fread( contents , *len, 1 , file) )
    {
        fclose(file);
        free(contents);
        error("IO", "Error reading contents of file '%s'.", path);
    }
    
    char *fixed_contents = calloc(sizeof(char), *len);
    strncpy(fixed_contents, contents, *len);
    free(contents);

    fclose(file);
    return fixed_contents;
}

void error(char const *from, char const *msg, char const *option)
{
    warns(from, msg, option);
    exit(1);
}

void errori(char const *from, char const *msg, int option)
{
    char buf[128];
    sprintf(buf, msg, option);
    printf("\n[%s]: %s (Line %lu)\n", from, buf, line_n);
    exit(1);
}

void warns(char const *from, char const *msg, char const *option)
{
    char buf[128];
    sprintf(buf, msg, option);
    printf("\n[%s]: %s (Line %lu)\n", from, buf, line_n);
}