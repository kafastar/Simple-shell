#include "shell.h"

/* Function Prototypes */
char *get_full_path(char *cmd, char *path);

/**
 * execute_command - Executes a given command.
 * @tokens: A list of tokens/parsed input.
 * @path: The PATH variable content.
 * @progname: The name of the program/shell.
 *
 * Return: 1 on success, 0 on failure.
 */
int execute(char **tokens, char *path, char *progname)
{
	pid_t pid;
	int status;
	char *full_cmd;

	if (tokens[0] == NULL)
		return (1);

	full_cmd = get_full_path(tokens[0], path);
	if (full_cmd == NULL)
	{
		cmd_not_found(progname, tokens[0]);
		return (0);
	}

	pid = fork();
	if (pid == 0) /* Child process */
	{
		if (execve(full_cmd, tokens, NULL) == -1)
			perror(progname);

		exit(EXIT_FAILURE);
	}
	else if (pid < 0) /* Error forking */
	{
		perror(progname);
	}
	else /* Parent process */
	{
		do {
			(void)waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	free(full_cmd);
	return (1);
}

/**
 * get_full_path - Locates the full path of a command using PATH.
 * @cmd: The command to locate.
 * @path: The PATH variable content.
 *
 * Return: The full path of the command or NULL.
 */
char *get_full_path(char *cmd, char *path)
{
	char *token, *tmp, *buf, *full_path;
	struct stat st;

	tmp = _strdup(path);
	token = strtok(tmp, ":");
	while (token != NULL)
	{
		buf = _strcat(token, "/");
		full_path = _strcat(buf, cmd);
		if (stat(full_path, &st) == 0)
		{
			free(tmp);
			free(buf);
			return (full_path);
		}
		free(buf);
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(tmp);
	return (NULL);
}
