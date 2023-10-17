#include "shell.h"

/**
 * main - Main entry point for our custom shell.
 * @argc: The number of arguments.
 * @argv: The argument vector.
 *
 * Return: 0 on success, otherwise the appropriate error code.
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char **tokens;
	size_t len = 0;
	ssize_t read;
	char *path = getenv("PATH");
	char *progname = argv[0];

	if (argc > 1)
	{
		fprintf(stderr, "%s: Error: Too many arguments\n", progname);
		return (1);
	}

	while (1)
	{
		printf("#cisfun$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			printf("\n");
			free(line);
			return (0);
		}
		else if (strncmp(line, "exit\n", 5) == 0)
		{
			free(line);
			return (0);
		}
		tokens = tokenize(line, " ");
		if (tokens[0])
		{
			execute(tokens, path, progname);
			free_tokens(tokens);
			free(line);
			line = NULL;
		}
	}
	return (0);
}
