#include "shell.h"

/**
 * _setenv - custom setenv function
 * @name: Input value
 * @value: Input value
 * @overwrite: Input value
 * Return: Return success
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	size_t namelen, valuelen, bufferlen;
	char *buffer;
	int result;
	char *existing_value;

	if (name == NULL || value == NULL || name[0] == '\0'
	    || mystrchr(name, '=') != NULL)
		return (-1);
	existing_value = _getenv(name);
	if (existing_value != NULL && !overwrite)
		return (0);
	namelen = ccount_str(name);
	valuelen = ccount_str(value);
	bufferlen = namelen + valuelen + 2;
	buffer = (char *)malloc(bufferlen);
	if (buffer == NULL)
		return (-1);
	_snprintf(buffer, bufferlen, "%s=%s", name, value);
	result = _putenv(buffer);
	free(buffer);
	return (result);
}
/**
 * _getenv - getenv function
 * @name: Input value
 * Return: Returns a char
 */
char *_getenv(const char *name)
{
	int i;
	size_t len = ccount_str(name);

	if (environ == NULL || name == NULL || len == 0)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (mystrncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (&(environ[i][len + 1]));
	}

	return (NULL);
}
/**
 * _putenv - putenv function
 * @string: Input value
 * Return: Returns integer
 */
int _putenv(char *string)
{
	int stringLen, numEnvVars;
	char *existingEnvVar;
	char **newEnviron;

	if (string == NULL || string[0] == '\0' || mystrchr(string, '=') == NULL)
		return (-1);

	stringLen = count_str(string);
	existingEnvVar = _getenv(string);
	if (existingEnvVar != NULL)
	{
		mystrcpy(existingEnvVar, &string[stringLen + 1]);
		return (0);
	}
	numEnvVars = 0;
	while (environ[numEnvVars] != NULL)
		numEnvVars++;

	newEnviron = realloc(environ, (numEnvVars + 2) * sizeof(char *));
	if (newEnviron == NULL)
		return (-1);

	newEnviron[numEnvVars] = mystrdup(string);
	newEnviron[numEnvVars + 1] = NULL;
	environ = newEnviron;
	return (0);
}
/**
 * _vsnprintf - it prints all
 * @str: Input value
 * @size: Input value
 * @format: Input value
 * @args: Input value
 * Return: Return integer
 */

int _vsnprintf(char *str, size_t size, const char *format, va_list args)
{
	int written = 0, remaining = size - 1, width = 0, value1, result;
	char *value;

	if (str == NULL || size == 0 || format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (remaining <= 0)
			break;
		if (*format != '%')
		{
			*str++ = *format++;
			written++, remaining--;
		}
		else
		{
			format++;
			while (*format >= '0' && *format <= '9')
			{
				width = width * 10 + (*format - '0');
				format++;
			}
			switch (*format)
			{
			case 'd':
			case 'i':
			{
				value1 = va_arg(args, int);
				result = _snprintf(str, remaining, "%*d", width, value1);
				if (result < 0 || result >= remaining)
					return (-1);
				written += result;
				remaining -= result;
				str += result;
				break;
			}
			case 's':
			{
				value = va_arg(args, char *);
				result = _snprintf(str, remaining, "%*s", width, value);
				if (result < 0 || result >= remaining)
					return (-1);
				written += result;
				remaining -= result;
				str += result;
				break;
			}
			default:
				format++;
				break;
			}
			format++;
		}
	}
	*str = '\0';
	return (written);
}
/**
 * _unsetenv - unsetenv function
 * @name: Input value
 * Return: Return an integer
 */

int _unsetenv(const char *name)
{
	int nameLen, i, j;

	if (name == NULL || name[0] == '\0' || mystrchr(name, '=') != NULL)
		return (-1);

	nameLen = ccount_str(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (mystrncmp(name, environ[i], nameLen) == 0 && environ[i][nameLen] == '=')
		{
			for (j = i; environ[j] != NULL; j++)
				environ[j] = environ[j + 1];

			return (0);
		}
	}

	return (0);
}
