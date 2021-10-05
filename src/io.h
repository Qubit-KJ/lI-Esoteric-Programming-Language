#ifndef io_h
#define io_h

#include <stddef.h>

char *load_file(char const *path, size_t *len);

void printstril(char *str);
void printchril(char chr);

#endif /* io_h */
