#include "shell.h"
/**
 * print_prompt - function that print the prompt
 */
void print_prompt(void)
{
	char prompt[] = "$ ";

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, count_str(prompt));
	}
}
/**
 * exit_shell - function that exits from shell
 */
void exit_shell(void)
{
	exit(EXIT_SUCCESS);
}
/**
 * find_command_path - function that find paths
 * @command: command variable
 * Return: Returns a pointer
 */
char *find_command_path(const char *command)
{
	char *path = _getenv("PATH");

	if (access(command, X_OK) == 0)
	{
		return (mystrdup(command));
	}
	if (path != NULL)
	{
		char *path_copy = mystrdup(path);
		char *dir = path_copy;
		char path[MAX_COMMAND_LENGTH];

		while (dir != NULL)
		{
			_snprintf(path,
				  MAX_COMMAND_LENGTH, "%s/%s", dir, command);
			if (access(path, X_OK) == 0)
			{
				free(path_copy);
				return (mystrdup(path));
			}
			dir = strtok(NULL, ":");
		}
		free(path_copy);
	}
	return (NULL);
}
/**
 * cd_builtin - builtin function
 * @directory: Input variable
 */
void cd_builtin(const char *directory)
{
	char current_dir[1024];
	char* setenv_args[] = { "setenv", "PWD", NULL, NULL };

	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("getcwd");
		return;
	}

	if (directory == NULL || _strcmp(directory, "") == 0)
	{
		directory = _getenv("HOME");
		if (directory == NULL)
		{
			perror("cd");
			return;
		}
	}

	if (_strcmp(directory, "-") == 0)
	{
		directory = _getenv("OLDPWD");
		if (directory == NULL)
		{
			perror("cd");
			return;
		}
	}

	if (chdir(directory) == -1)
	{
		perror("chdir");
		return;
	}
	setenv_args[2] = (char*)directory;
	setenv_builtin(setenv_args);

}
/**
 * exit_shell_with_status - exit function
 */
void exit_shell_with_status(void)
{
	int status = 0;

	status = 42;
	exit(status);
}
