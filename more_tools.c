#include "shell.h"
/**
* ccount_str - counts the length of a string
* @str: the string iput
* Return: Returns the length of the string
*/
int ccount_str(const char *str)
{
	int counter = 0;

	while (*str)
	{
		counter = counter + 1;
		str++;
	}
	return (counter);
}
