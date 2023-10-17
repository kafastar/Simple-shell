#include "shell.h"
#include <errno.h>

/**
 * print_error - Prints a formatted error message to stderr.
 * @args: The arguments array.
 * @err: The error message.
 */
void print_error(char **args, char *err)
{
	fprintf(stderr, "%s: %s: %s\n", args[0], args[1], err);
}

/**
 * handle_error - Handles errors based on their error codes.
 * @err_code: The error code.
 * @args: The arguments array.
 */
void handle_error(int err_code, char **args)
{
	switch (err_code)
	{
	case ENOENT:
		print_error(args, "No such file or directory");
		break;
	case EACCES:
		print_error(args, "Permission denied");
		break;
	default:
		print_error(args, "Unknown error occurred");
	}
}
