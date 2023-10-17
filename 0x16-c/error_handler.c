#include "shell.h"

/**
 * cmd_not_found - Handles the "command not found" error.
 * @progname: The name of the program/shell.
 * @cmd: The command that was not found.
 */
void cmd_not_found(char *progname, char *cmd)
{
	write(STDERR_FILENO, progname, _strlen(progname));
	write(STDERR_FILENO, ": 1: ", 5);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * _perror - Prints error messages.
 * @msg: The error message.
 */
void _perror(char *msg)
{
	write(STDERR_FILENO, msg, _strlen(msg));
}

/**
 * exit_error - Handles exit errors.
 * @progname: The name of the program/shell.
 * @cmd: The command that caused the error.
 */
void exit_error(char *progname, char *cmd)
{
	write(STDERR_FILENO, progname, _strlen(progname));
	write(STDERR_FILENO, ": 1: exit: Illegal number: ", 27);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, "\n", 1);
}
