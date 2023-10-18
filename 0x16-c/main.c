#include "shell.h"

/**
 * free_resources - Function to free allocated resources.
 * @line: The line to free.
 * @tokens: The tokens to free.
 */
void free_resources(char *line, char **tokens)
{
	if (line)
		free(line);
	if (tokens)
		free_tokens(tokens);
}

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
	const char *prompt = "#cisfun$ ";

	if (argc > 1)
	{
		fprintf(stderr, "%s: Error: Too many arguments\n", progname);
		return (1);
	}

	while (1)
	{
		printf("%s", prompt);
		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			printf("\n");
			free_resources(line, tokens);
			return (0);
		}
		if (strncmp(line, "exit\n", 5) == 0)
		{
			free_resources(line, tokens);
			return (0);
		}

		tokens = tokenize(line, " ");
		if (tokens[0])
		{
			execute(tokens, path, progname);
			free_resources(line, tokens);
			line = NULL;
		}
	}
	return (0);
}
