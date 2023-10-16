#ifndef SHELL_H
#define SHELL_H

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Function Prototypes */

/* main.c */
void process_line(char *line, FILE *fp);
int check_builtins(char **args);


/* parser.c */
char **tokenize_line(char *line);
char **handle_operators(char *line);

/* path_utils.c */
char *get_cmd_path(char *cmd);
char *get_current_dir(void);

/* builtins.c */
int execute_builtin(char **args);
int shell_exit(char **args);
int shell_env(char **args);
int shell_setenv(char **args);
int shell_unsetenv(char **args);
int shell_cd(char **args);
int shell_alias(char **args);

/* utils.c */
char *_strdup(const char *str);
int _strcmp(const char *s1, const char *s2);
size_t _strlen(const char *str);
void free_array(char **array);

/* custom_getline.c */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);

/* custom_tokenizer.c */
char **custom_tokenizer(char *input, char delimiter);

/* Structures */
typedef struct builtin_struct
{
	char *name;
	int (*func)(char **args);
} builtin_t;

#endif /* SHELL_H */

