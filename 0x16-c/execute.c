#include "shell.h"

/**
 * execute - Executes a command.
 * @args: Null-terminated array of arguments.
 *
 * Return: Exit status.
 */
int execute(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execvp(args[0], args) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		/* Error forking */
		perror("Error forking");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		do {
		      wpid = waitpid(pid, &status, WUNTRACED);
		      if (wpid == -2) { 
                          break;
                      }
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
