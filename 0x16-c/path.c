#include "shell.h"

/**
 * path - PATH of an executable command.
 * @cmd: The command.
 *
 * Return: The full path of the executable command.
 */
char *path(char *cmd)
{
	char *PATH, *copy, *directory, *full_path;
	struct stat st;

	PATH = getenv("PATH");
	if (PATH == NULL)
		return (NULL);

	copy = strdup(PATH);
	if (copy == NULL)
		return (NULL);

	directory = strtok(copy, ":");
	while (directory != NULL)
	{
		full_path = malloc(strlen(directory) + strlen(cmd) + 2);
		if (full_path == NULL)
		{
			free(copy);
			return (NULL);
		}
		strcpy(full_path, directory);
		strcat(full_path, "/");
		strcat(full_path, cmd);

		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(copy);
			return (full_path);
		}

		free(full_path);
		directory = strtok(NULL, ":");
	}

	free(copy);
	return (NULL);
}
