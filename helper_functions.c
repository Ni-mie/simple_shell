#include "shell.h"

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
void _fprintf(const char* format, ...)
{
	char buffer[4096];
	va_list args;
	int length = vsnprintf(buffer, sizeof(buffer), format, args);

	va_start(args, format);
	va_end(args);

	write(STDERR_FILENO, buffer, length);
}
int _snprintf(char* buffer, size_t size, const char* format, ...)
{
	va_list args;
	int length = vsnprintf(buffer, size, format, args);

	va_start(args, format);
	va_end(args);

	return (length);
}
int _strcmp(const char* str1, const char* str2)
{
	int i = 0;

	while (str1[i] != '\0' && str1[i] == str2[i])
	{
		i++;
	}

	return str1[i] - str2[i];
}
