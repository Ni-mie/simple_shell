#include "shell.h"

void print_prompt()
{
	char prompt[] = "$ ";
	write(STDOUT_FILENO, prompt, count_str(prompt));
}

void exit_shell()
{
	 char goodbye[] = "\nGoodbye!\n";
	 write(STDOUT_FILENO, goodbye, count_str(goodbye));
	 exit(EXIT_SUCCESS);
}
char* find_command_path(const char* command)
{
	char* path = getenv("PATH");
	if (access(command, X_OK) == 0)
	{
		return strdup(command);
	}
	if (path != NULL)
	{
		char* path_copy = strdup(path);
		char* dir = path_copy;
		char* delimiter = strchr(dir, ':');
		char path[MAX_COMMAND_LENGTH];
		while (dir != NULL)
		{
			 if (delimiter != NULL)
				 *delimiter = '\0';
			 _snprintf(path,
				  MAX_COMMAND_LENGTH, "%s/%s", dir, command);
			 if (access(path, X_OK) == 0)
			 {
				 free(path_copy);
				 return strdup(path);
			 }
			 if (delimiter != NULL)
			 {
				 dir = delimiter + 1;
				 delimiter = strchr(dir, ':');
			 }
			 else
			 {
				 dir = NULL;
			 }
		}
		free(path_copy);
	}
	return (NULL);
}
void cd_builtin(char* directory)
{
	char current_dir[1024];
	char* setenv_args[] = { "setenv", "PWD", NULL, NULL };

	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("getcwd");
		return;
	}
	if (directory == NULL || strcmp(directory, "") == 0)
	{
		directory = getenv("HOME");
		if (directory == NULL)
		{
			perror("cd");
			return;
		}
	}
	if (_strcmp(directory, "-") == 0)
	{
		directory = getenv("OLDPWD");
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

	 if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	 {
		 perror("getcwd");
		 return;
	 }

	 write(STDOUT_FILENO, current_dir, count_str(current_dir));
	 write(STDOUT_FILENO, "\n", 1);
}
