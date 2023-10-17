#include "shell.h"

/*
 **
 * check_builtins - Checks if the command is a builtin.
 * @args: The command arguments.
 * Return: 1 if command is a builtin, 0 otherwise.
 */
int check_builtins(char **args)
{
	if (_strcmp(args[0], "cd") == 0)
		return (builtin_cd(args));
	if (_strcmp(args[0], "exit") == 0)
		return (builtin_exit(args));
	if (_strcmp(args[0], "env") == 0)
		return (builtin_env(args));
	return (0);
}

/**
 * builtin_cd - Changes the current directory.
 * @args: The command arguments.
 * Return: 1 on success, 0 otherwise.
 */
int builtin_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
		return (0);
	}
	if (chdir(args[1]) != 0)
		perror("lsh");
	return (1);
}

/**
 * builtin_exit - Exits the shell.
 * @args: The command arguments.
 * Return: 1 on success, 0 otherwise.
 */
int builtin_exit(char **args)
{
	(void)args;
	exit(0);
}

/**
 * builtin_env - Prints the environment.
 * @args: The command arguments.
 * Return: 1 on success, 0 otherwise.
 */
int builtin_env(char **args)
{
	char **env = environ;

	(void)args;
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (1);
}
