#include "shell.h"
#include <string.h>

/**
 * get_path - Retrieves the PATH value from the environment.
 * @environ: The environment variables.
 *
 * Return: The value of PATH or NULL if PATH doesn't exist.
 */
char *get_path(char **environ)
{
	int i = 0;

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (&environ[i][5]);
		i++;
	}
	return (NULL);
}

/**
 * path_concat - Concatenates the directory and command to get the full path.
 * @dir: The directory.
 * @cmd: The command.
 *
 * Return: The full path.
 */
char *path_concat(char *dir, char *cmd)
{
	char *full_path;
	int len_dir, len_cmd;

	len_dir = _strlen(dir);
	len_cmd = _strlen(cmd);
	full_path = malloc(len_dir + len_cmd + 2);
	if (!full_path)
		return (NULL);

	_strcpy(full_path, dir);
	_strcat(full_path, "/");
	_strcat(full_path, cmd);

	return (full_path);
}

/**
 * cmd_in_path - Checks if the command is in the PATH.
 * @cmd: The command to check.
 * @environ: The environment variables.
 *
 * Return: The full path to the command or NULL if it's not found.
 */
char *cmd_in_path(char *cmd, char **environ)
{
	char *path, *dir;
	char *s;
	char *full_path;

	path = get_path(environ);
	if (!path)
		return (NULL);
	s = _strdup(path);

	dir = strtok(s, ":");
	while (dir)
	{
		full_path = path_concat(dir, cmd);
		if (access(full_path, F_OK) == 0)
		{
			free(s);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(s);
	return (NULL);
}
