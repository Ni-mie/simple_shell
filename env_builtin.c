#include "shell.h"
/**
 * env_builtin - environment builtin function
 */
void env_builtin(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		char *curr = *env;

		while (*curr != '\0')
		{
			write(STDOUT_FILENO, curr, 1);
			curr++;
		}
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
/**
 * custom_getline - getline function
 * @lineptr: input value
 * @n: Input value
 * Return: Always success
 */
ssize_t custom_getline(char **lineptr, size_t *n)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_pos, bytes_read;
	size_t count = 0, size = *n;
	char *line = *lineptr;
	int eof_reached = 0;
	char *new_line = realloc(*lineptr, size);

	if (lineptr == NULL || n == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*lineptr = malloc(BUFFER_SIZE);
		if (*lineptr == NULL)
		{
			return (-1);
		}
		*n = BUFFER_SIZE;
	}

	while (1)
	{
		if (buffer_pos >= (size_t)bytes_read)
		{
			bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (bytes_read <= 0)
			{
				eof_reached = 1;
				break;
			}
			buffer_pos = 0;
		}

		while (buffer_pos < (size_t)bytes_read)
		{
			if (count >= size - 1)
			{
				size *= 2;
				if (new_line == NULL)
					return (-1);
				line = new_line;
				*lineptr = new_line;
				*n = size;
			}
			if (buffer[buffer_pos] == '\n')
			{
				buffer_pos++;
				line[count] = '\0';
				return (count);
			}
			line[count] = buffer[buffer_pos];
			count++;
			buffer_pos++;
		}
	}

	if (count > 0 || eof_reached)
	{
		line[count] = '\0';
		return (count);
	}

	return (-1);
}
/**
 * setenv_builtin - set_environment function
 * @args: Input value
 */

void setenv_builtin(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
		_fprintf("Usage: setenv VARIABLE VALUE\n");
	if (setenv(args[1], args[2], 1) == -1)
	{
		perror("setenv");
		return;
	}
}
/**
 * unsetenv_builtin - set_environment function
 * @args: Input value
 */
void unsetenv_builtin(char **args)
{
	if (args[1] == NULL)
	{
		_fprintf("Usage: unsetenv VARIABLE\n");
		return;
	}

	if (unsetenv(args[1]) == -1)
	{
		perror("unsetenv");
		return;
	}
}
