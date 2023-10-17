#include "shell.h"

/**
 * extend_buffer - Reallocates memory for the buffer.
 * @line: The current buffer.
 * @bufsize: The current buffer size.
 *
 * Return: A pointer to the new buffer, or NULL on failure.
 */
char *extend_buffer(char *line, size_t *bufsize)
{
	char *temp;

	*bufsize += 1024;
	temp = realloc(line, *bufsize);
	if (!temp)
		return (NULL);
	return (temp);
}

/**
 * process_character - Process a character read from the stream.
 * @c: The character.
 * @line: The buffer.
 * @position: The current position in the buffer.
 * @bufsize: The buffer size.
 *
 * Return: 1 if the line is complete, 0 otherwise.
 */
int process_character(int c, char *line, size_t *position, size_t *bufsize)
{
	char *temp;

	if (c == EOF || c == '\n')
	{
		line[*position] = '\0';
		return (1);
	}
	else
	{
		line[*position] = c;
	}

	(*position)++;

	if (*position >= *bufsize)
	{
		temp = extend_buffer(line, bufsize);
		if (!temp)
		{
			line[*position] = '\0';
			return (1);
		}
		line = temp;
	}

	return (0);
}

/**
 * getline_custom - Custom implementation of getline.
 * @lineptr: Pointer to the buffer that holds the line read.
 * @n: Pointer to the size of the buffer.
 * @stream: Input stream to read from.
 *
 * Return: The number of characters read, or -1 on failure.
 */
ssize_t getline_custom(char **lineptr, size_t *n, FILE *stream)
{
	char *line, *temp;
	size_t bufsize = 1024, position = 0, c;

	if (!lineptr || !n || !stream)
		return (-1);

	if (*lineptr == NULL || *n < bufsize)
	{
		temp = extend_buffer(*lineptr, &bufsize);
		if (!temp)
			return (-1);
		*lineptr = temp;
		*n = bufsize;
	}

	line = *lineptr;

	while (1)
	{
		c = fgetc(stream);
		if (process_character(c, line, &position, &bufsize))
			return (position);
	}

	return (-1);
}
