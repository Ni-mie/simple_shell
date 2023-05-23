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

/**
 * mystrcat - it concatenate two strings
 * @dest: destination string
 * @src: source string
 * Return: Returns the concatenated string
 */

char *mystrcat(char *dest, const char *src)
{
	int ldest = 0, lsrc = 0, totallen = 0, i, j, k = 0, ccount = 0, ncount = 0;
	char *ptr;

	ldest = ldest + count_str(dest);

	while (src[lsrc] != '\0')
		lsrc = lsrc + 1;
	totallen = ldest + lsrc + 1;
	ptr = malloc(totallen);
	if (ptr == NULL)
	{
		display_str("Unable to allocate memory\n");
		exit(0);
	}
	for (i = 0; i < ldest; i++)
	{
		*(ptr + i) = dest[i];
	}
	for (j = i; j < totallen - 1; j++)
	{
		*(ptr + j) = src[k];
		k++;
	}
	while (ccount < ldest)
	{
		dest++;
		ccount = ccount + 1;
	}
	while (ncount < lsrc)
	{
		*dest = src[ncount];
		ncount = ncount + 1;
		dest++;
	}
	return (ptr);
}
/**
 * mystrcpy - it copys from source to dest
 * @dest: Destination variable
 * @src: Source destination
 * Return: Returns the pointer
 */
char *mystrcpy(char *dest, const char *src)
{
	int lsrc = 0, totallen = 0, i;
	char *ptr;

	while (src[lsrc] != '\0')
		lsrc = lsrc + 1;
	totallen = lsrc + 1;
	ptr = malloc(totallen);
	if (ptr == NULL)
	{
		display_str("Unable to allocate memory\n");
		exit(0);
	}
	for (i = 0; i < lsrc + 1; i++)
	{
		*dest = src[i];
		*(ptr + i) = src[i];
		dest++;
	}
	return (ptr);
}
