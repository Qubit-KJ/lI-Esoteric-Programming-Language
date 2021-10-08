#ifndef __UTIL_H
#define __UTIL_H

#define ILL_HIGH 'I'

typedef unsigned long long Ill_Binary;
#define ILL_BIN_SIZE (sizeof(Ill_Binary))

Ill_Binary illtobin(char *ill);

// for ensuring there is no character but I, l, ' ', and '\n'
int is_valid_char(char chr);
int is_valid_word(char *str);

// for testing purposes
void print_bin(Ill_Binary n);

#endif