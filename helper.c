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
/**
 * mystrncmp - it compares the ascii of two string in ntimes
 * @str1: Input variable of str1
 * @str2: Input variable of str2
 * @n: Input variable of ntimes
 * Return: Returns the ascii differences between str1 and str2
 */

int mystrncmp(const char *str1, const char *str2, int n)
{
	int len1 = 0, len2 = 0, counter = 0, i = 0, j = 0;

	while (str1[i] != '\0')
		len1 = len1 + 1, i = i + 1;
	while (str2[j] != '\0')
		len2 = len2 + 1, j = j + 1;
	if (len1 >= n && len2 >= n)
	{
		while (counter < n)
		{
			if (*str1 < *str2)
				return (*str1 - *str2);
			else if (*str1 > *str2)
				return (*str1 - *str2);
			counter = counter + 1;
			str1++, str2++;
		}
	}
	else if ((len1 < n) && len1 <= len2)
	{
		while (counter < len1)
		{
			if (*str1 < *str2)
				return (*str1 - *str2);
			else if (*str1 > *str2)
				return (*str1 - *str2);
			counter = counter + 1;
			if (counter == len1 && *str1 == *str2 && len1 == len2)
				return (0);
			else if (counter == len1)
				return (*str1 - *str2);
			str1++, str2++;
		}
	}
	else if ((len2 < n) && len2 <= len1)
	{
		while (counter < len2)
		{
			if (*str1 < *str2)
				return (*str1 - *str2);
			else if (*str1 > *str2)
				return (*str1 - *str2);
			counter = counter + 1;
			if (counter == len2 && *str1 == *str2 && len1 == len2)
				return (0);
			else if (counter == len2)
				return (*str1 - *str2);
			str1++, str2++;
		}
	}
	return (0);
}
