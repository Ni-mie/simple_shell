#include "shell.h"

/**
 * _atoi - string to integer function
 * @str: Input variable
 * Return: Return Result
 */

int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			break;
		}

		result = result * 10 + (str[i] - '0');
	}

	return (sign * result);
}

/**
 * _fprintf - fprint function
 * @format: Input variable
 */

void _fprintf(const char *format, ...)
{
	char buffer[4096];
	va_list args;
	int length = vsnprintf(buffer, sizeof(buffer), format, args);

	va_start(args, format);
	va_end(args);

	write(STDERR_FILENO, buffer, length);
}

/**
 * _snprintf - print function
 * @buffer: Input variable
 * @size: input variable
 * @format: Input variable
 * Return: Return Length
 */

int _snprintf(char *buffer, size_t size, const char *format, ...)
{
	va_list args;
	int length = vsnprintf(buffer, size, format, args);

	va_start(args, format);
	va_end(args);

	return (length);
}
/**
 * _strcmp - string compares function
 * @str1: string one input
 * @str2: string two input
 * Return: Return success
 */

int _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str1[i] == str2[i])
	{
		i++;
	}

	return (str1[i] - str2[i]);
}

/**
* mystrdup - function that does string duplicate
* @s: Input value s
* Return: Returns duplicate
*/

char *mystrdup(const char *s)
{
	int counter = 0, i = 0, z = 0;
	char *dupstring;

	while (s[z] != '\0')
	{
		counter = counter + 1;
		z = z + 1;
	}
	counter = counter + 1;
	dupstring = malloc(counter);
	if (dupstring == NULL)
	{
		display_str("Unable to allocate memory\n");
		exit(0);
	}
	while (*s)
	{
		*(dupstring + i) = *s;
		i = i + 1;
		s++;
	}
	return (dupstring);
}
