#include "shell.h"

/**
 * _puts - Custom function to print a string to stdout.
 * @str: The string to print.
 */
void _puts(char *str);

/**
 * builtin_check - Checks if the command is a built-in.
 * @cmd: The command to check.
 *
 * Return: 1 if it's a built-in, 0 otherwise.
 */
int builtin_check(char *cmd)
{
	if (_strcmp(cmd, "exit") == 0 || _strcmp(cmd, "env") == 0)
		return (1);
	return (0);
}

/**
 * execute_builtin - Executes the built-in command.
 * @cmd: The command to execute.
 * @env: The environment variables.
 *
 * Return: 1 if the shell should continue, 0 if it should exit.
 */
int execute_builtin(char *cmd, char **env)
{
	if (_strcmp(cmd, "exit") == 0)
		return (0);
	if (_strcmp(cmd, "env") == 0)
	{
		print_env(env);
		return (1);
	}
	return (1);
}

/**
 * print_env - Prints the environment variables.
 * @env: The environment variables.
 */
void print_env(char **env)
{
	int i = 0;

	while (env[i])
	{
		_puts(env[i]);
		_puts("\n");
		i++;
	}
}

/**
 * _puts - Custom function to print a string to stdout.
 * @str: The string to print.
 */
void _puts(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
