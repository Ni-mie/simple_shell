#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdarg.h>

#define MAX_COMMAND_LENGTH 20
#define MAX_ARGS 10
#define BUFFER_SIZE 1024

extern char **environ;

void print_prompt();
void exit_shell();
void execute();
void execute_command(char* command);
char* find_command_path(const char* command);
void env_builtin();
ssize_t custom_getline(char **lineptr, size_t *n);
int _atoi(const char *str);
void setenv_builtin(char** args);
void unsetenv_builtin(char** args);
void _fprintf(const char* format, ...);
int _snprintf(char* buffer, size_t size, const char* format, ...);
void cd_builtin(char* directory);
int _strcmp(const char* str1, const char* str2);
int count_str(char *str);
void display_str(char *str);
int count_num(long int num);
int mypow(int num, int power);
int _putchar(char c);
#endif