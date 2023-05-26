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
int cd_builtin(char *args)
{
	char *newDir;
	char *oldDir = getcwd(NULL, 0);

	if (args == NULL || _strcmp(args, "~") == 0)
	{
		newDir = _getenv("HOME");
	}
	else if (_strcmp(args, "-") == 0)
	{
		newDir = _getenv("OLDPWD");
	}
	else
	{
		newDir = args;
	}
	if (oldDir == NULL)
	{
		perror("getcwd");
		return (-1);
	}
	if (chdir(newDir) == -1)
	{
		perror("cd");
		free(oldDir);
		return (-1);
	}
	  if (setenv("OLDPWD", oldDir, 1) == -1)
	  {
		  perror("setenv");
		  free(oldDir);
		  return (-1);
	  }
	  if (setenv("PWD", getcwd(NULL, 0), 1) == -1)
	  {
		  perror("setenv");
		  free(oldDir);
		  return (-1);
	  }
	  free(oldDir);
	  return (0);
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
