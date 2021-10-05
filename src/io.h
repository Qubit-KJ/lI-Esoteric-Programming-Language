#ifndef io_h
#define io_h

#include <stddef.h>

char *load_file(char const *path, size_t *len);

void error(char const *from, char const *msg, char const *option);
void errori(char const *from, char const *msg, int option);
void warns(char const *from, char const *msg, char const *option);

void printstril(char *str);
void printchril(char chr);

#endif /* io_h */
