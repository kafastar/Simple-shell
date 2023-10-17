#include "shell.h"

/**
 * tokenize - Tokenizes a string into an array of tokens.
 * @str: The string to tokenize.
 * @delim: The delimiter to tokenize with.
 *
 * Return: A NULL-terminated array of tokens, or NULL on failure.
 */
char **tokenize(char *str, const char *delim)
{
	int bufsize = 64, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("shell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("shell: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, delim);
	}
	tokens[position] = NULL;
	return (tokens);
}
