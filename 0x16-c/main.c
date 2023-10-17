#include "shell.h"

/**
 * process_line - Process a single line of input.
 * @line: The line to process.
 * @fp: The file pointer to read from.
 */
void process_line(char *line, FILE *fp)
{
     const char *delim = " \t\r\n\a";
    char **args = tokenize(line, delim);
	
	if (fp == stdin)
		printf("$ ");


	if (args[0] == NULL)
	{
		free(args);
		return;
	}

	/* Handle builtins or execute command */
	if (check_builtins(args) == 0)
		execute(args);

	free(args);
}

/**
 * main - Entry point of the shell.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, otherwise the status of the last executed command.
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	FILE *fp = stdin;

	/* If there's a command line argument, open the file */
	if (argc > 1)
	{
		fp = fopen(argv[1], "r");
		if (!fp)
		{
			perror("Error opening file");
			return (1);
		}
	}

	/* Main loop */
	while ((read = getline(&line, &len, fp)) != -1)
	{
		process_line(line, fp);
	}

	free(line);

	/* Close the file if it's not stdin */
	if (fp != stdin)
		fclose(fp);

	return (0);
}
