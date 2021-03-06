#include "../../tests/getIndex.h"

// this function returns the index of the first occurrence of the given character in the given string
int getIndex(const char *string, char chr)
{
	int counter = 0;
	int length = (int) strlen(string);
	for (; counter < length && string[counter] != chr; counter++);
	return counter;
}
