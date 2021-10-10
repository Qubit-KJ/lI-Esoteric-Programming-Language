#ifndef io_h
#define io_h

#include <stdio.h>

#define USE_Il 1

char *load_file(char const *path, size_t *len);

FILE *open_file(char const *path);

void error(char *errmsg);

void printstril(char *str);
void printchril(char chr);

#endif /* io_h */
