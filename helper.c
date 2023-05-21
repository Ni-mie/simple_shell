#include "shell.h"

/**
* mystrchr - it searches for a string and return its first occurence
* @str: Input value of the string
* @c: Input value of the search input
* Return: Return a char pointer
*/
char *mystrchr(const char *str, char c)
{
	int i = 0, counter = 0, pcount = 0, allocatedcount = 0, j = 0;
	char *mystr;

	while (str[i] != '\0')
	{
		counter = counter + 1;
		i = i + 1;
	}
	while (*str != c)
	{
		pcount = pcount + 1;
		str++;
	}
	allocatedcount = counter - pcount + 1;
	mystr = malloc(allocatedcount);
	if (mystr == NULL)
	{
		display_str("Memory failed to allocate\n");
		exit(0);
	}
	while (*str)
	{
		*(mystr + j) = *str;
		j = j + 1;
		str++;
	}
	return (mystr);
}
