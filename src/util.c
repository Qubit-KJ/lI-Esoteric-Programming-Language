#include "util.h"
#include "io.h"

#include <string.h>
#include <unistd.h>
#include <stdio.h>

Ill_Binary illtobin(char *ill)
{
	size_t ill_len = strlen(ill), n;

	// if the string is too big to store in ill_bin_t, throw an error
	if (ill_len > ILL_BIN_SIZE)
	{
		error("String too long to convert to id.");
	}

	Ill_Binary outbin = 0;

	for (size_t i = 0; i < ill_len; i++)
	{
		// character is invalid, not I or l
		if (!is_valid_char(ill[i])) error("Character is not I or l");
		if (ill[i] == ILL_HIGH) outbin |= 1ULL << n; n++;
	}
	return outbin;
}



int is_valid_char(char chr)
{
	return chr == 'I' || chr == 'l' || chr == ' ' || chr == '\n';
}

int is_valid_word(char *str)
{
	for (char *c = str; *c != '\0'; c++)
	{
		if (!is_valid_char(*c)) return 1;
	}
	return 0;
}



void print_bin(Ill_Binary bin)
{
    if (bin >> 1) {
        print_bin(bin >> 1);
    }
    write(STDOUT_FILENO, (bin & 1) ? "1" : "0", 1);
}