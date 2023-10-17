#include "shell.h"

/**
 * _getline - A custom function that reads a line from standard input.
 * @buffer: The buffer to store the read line.
 * @buf_size: The size of the buffer.
 *
 * Return: The number of characters read, or -1 on failure or EOF.
 */
ssize_t _getline(char **buffer, size_t *buf_size)
{
	ssize_t bytes_read;
	size_t n = 0;

	if (!buffer || !buf_size)
	{
		errno = EINVAL;
		return (-1);
	}

	bytes_read = getline(buffer, &n, stdin);
	if (bytes_read == -1 && errno == 0)
	{
		return (-1);
	}
	else if (bytes_read == -1)
	{
		return (-1);
	}

	/* Adjust the buffer size */
	*buf_size = n;

	return (bytes_read);
}
