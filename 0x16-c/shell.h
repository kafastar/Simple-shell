#ifndef SHELL_H
#define SHELL_H

#define TOKENS_BUFFER_SIZE 64 

/* Include libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

/* Function Prototypes */
char *read_line(void);
char **split_line(char *line);
int execute_cmd(char **args);
char *find_cmd_in_PATH(char *cmd);
int launch_process(char **args);
void free_grid(char **grid);
int handle_builtin_cmds(char **args);
char **tokenize(char *str, char *delim);
int execute(char **tokens, char *path, char *progname);
void free_tokens(char **tokens);
void print_env(char **env);
void cmd_not_found(char *progname, char *cmd);

/* Built-in function prototypes */
int builtin_cd(char **args);
int builtin_exit(char **args);
int builtin_env(char **args);
int builtin_setenv(char **args, char ***env);
int builtin_unsetenv(char **args, char ***env);
int builtin_help(char **args);

/* Error handler */
void print_error(char *arg);

/* Utility function prototypes */
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);

#endif /* SHELL_H */

