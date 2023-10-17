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
#include <errno.h> 

/* Function Prototypes */
extern char **environ;

/* main.c */
void process_line(char *line, FILE *fp);
int check_builtins(char **args);

/* execute.c */
int execute(char **args);

/* tokenize.c */
char **tokenize(char *str, const char *delim);

/* path.c */
char *get_cmd_path(char *cmd);
char *get_current_dir(void);

/* builtins.c */
int execute_builtin(char **args);
int shell_exit(char **args);
int shell_env(char **args);
int shell_cd(char **args);
int builtin_cd(char **args);
int builtin_exit(char **args); 
int builtin_env(char **args);

/* utility_functions.c */
char *_strdup(const char *str);
int _strlen(char *str);
void free_array(char **array);
int _strcmp(const char *s1, const char *s2);

/* getline_custom.c */
ssize_t getline_custom(char **lineptr, size_t *n, FILE *stream);

/* Structures */
typedef struct builtin_struct
{
        char *name;
        int (*func)(char **args);
} builtin_t;

#endif /* SHELL_H */

