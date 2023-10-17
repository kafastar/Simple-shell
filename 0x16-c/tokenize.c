#include "shell.h"

/**
 * tokenize - Tokenizes a string into an array of tokens.
 * @str: The string to tokenize.
 * @delim: The delimiters to use.
 *
 * Return: A NULL-terminated array of tokens.
 */
char **tokenize(char *str, char *delim)
{
	int buf_size = TOKENS_BUFFER_SIZE, position = 0;
	char **tokens = malloc(buf_size * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("Tokenization error: memory allocation failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= buf_size)
		{
			buf_size += TOKENS_BUFFER_SIZE;
			tokens = realloc(tokens, buf_size * sizeof(char *));
			if (!tokens)
			{
				perror("Tokenization error: memory reallocation failed");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, delim);
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * free_tokens - Frees a list of tokens.
 * @tokens: A list of tokens.
 */
void free_tokens(char **tokens)
{
int i = 0;

if (tokens == NULL)
return;

while (tokens[i])
{
free(tokens[i]);
i++;
}

free(tokens);
}
