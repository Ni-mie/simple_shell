#include "shell.h"
/**
 * execute_command - executes all the command
 * @command: Input variable
 */
void execute_command(char *command)
{
	char *token = strtok(command, ";");
	int prev_status = 0;

	while (token != NULL)
	{
		if (count_str(token) > 0)
		{
			char *args[MAX_ARGS + 2];
			int n_args = 0;
			int arg_start = -1;
			int i;

			for (i = 0; token[i] != '\0'; i++)
			{
				if (token[i] == ' ' || token[i] == '\t')
				{
					if (arg_start != -1)
					{
						token[i] = '\0';
						args[n_args] = &token
							[arg_start];
						n_args++;
						arg_start = -1;
					}
				}
				else if (arg_start == -1)
				{
					arg_start = i;
				}
			}

			if (arg_start != -1)
			{
				args[n_args] = &token[arg_start];
				n_args++;
			}

			args[n_args] = NULL;

			if (_strcmp(args[0], "env") == 0)
			{
				env_builtin();
			}
			 if (_strcmp(args[0], "exit") == 0)
			 {
				 if (isatty(STDIN_FILENO))
				 {
					 if (n_args > 1)
					 {
						 int status = _atoi(args[1]);
						 exit(status);
					 }
					 else
					 {
						 exit(EXIT_SUCCESS);
					 }
				 }
				 else
					 return;
			 }
			else if (_strcmp(args[0], "cd") == 0)
			{
				if (n_args == 1)
					cd_builtin(NULL);
				else if (n_args == 2)
					cd_builtin(args[1]);
				else
					_fprintf("Invalid cd command\n");
			}
			else
			{
				pid_t pid = fork();

				if (pid == -1)
				{
					perror("fork");
					return;
				}
				else if (pid == 0)
				{
					if (execvp(args[0], args) == -1)
					{
						perror("execvp");
						_exit(EXIT_FAILURE);
					}
				}
				else
				{
					int status;

					if (waitpid(pid, &status, 0) == -1)
					{
						perror("waitpid");
						exit(EXIT_FAILURE);
					}

					if (_strcmp(token, "&&") == 0)
					{
						if (prev_status == 0
						    && status == 0)
							prev_status = 0;
						else
							prev_status = 1;
					}
					else if (_strcmp(token, "||") == 0)
					{
						if (prev_status == 0
						    || status == 0)
							prev_status = 0;
						else
							prev_status = 1;
					}
					else
					{
						prev_status = status;
					}
				}
			}
		}

		token = strtok(NULL, ";");
	}
}
/**
 * execute - execute function
 */
void execute(void)
{
	char command[MAX_COMMAND_LENGTH];
	int token_start = 0;
	int token_end = 0;
	int i = 0;
	char c;

	while (1)
	{
		print_prompt();

		i = 0;
		while ((c = getchar()) != EOF && c != '\n')
		{
			if (i < MAX_COMMAND_LENGTH - 1)
			{
				command[i++] = c;
			}
		}
		command[i] = '\0';

		if (c == EOF)
		{
			exit_shell();
		}
		if (count_str(command) == 0 || count_str(command) >=
		    MAX_COMMAND_LENGTH)
		{
			char invalid[] = "Invalid command\n";

			write(STDOUT_FILENO, invalid, count_str(invalid));
			continue;
		}
		if (_strcmp(command, "exit") == 0)
		{
			exit_shell();
		}
		else if (mystrncmp(command, "exit ", 5) == 0)
		{
			execute_command(command);
			break;
		}
		else if (_strcmp(command, "cd") == 0)
		{
			cd_builtin(NULL);
		}
		else if (mystrncmp(command, "cd ", 3) == 0)
		{
			char *directory = command + 3;

			cd_builtin(directory);
		}
		while (command[token_end] != '\0')
		{
			if (command[token_end] == ';')
			{
				command[token_end] = '\0';
				execute_command(&command[token_start]);
				token_start = token_end + 1;
			}
			 token_end++;
		}
		if (token_start < token_end)
		{
			execute_command(&command[token_start]);
		}
	}
}
