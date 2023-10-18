#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

#define buffer 1024

/* Helper functions */
int _putchar(char *c);
int _strlen(char *s);
int _atoi(char *str);
int _path(char *path);
char *which_path(char *filename, char *path);
char *_strcpy(char *dest,char *src);
char *_strcat(char *dest, char *src);
int _strncmp(char *str1, char *str2, int n);

/* shell functions */
int prompt_handler(size_t *len, char **cmd_sh);

int execute_cmd(char *command, char *tokens[], int *exit_stat);

int check_env(int n, char **argv, char **tokens, int *exit_stat);

int _exe(char **argv, char **tokens, char **command, int *exit_stat);

void print_error(char **tokens, char **argv, int *exit_stat);

int _unsetenv(char *var);

char *_getenv(char *var);
#endif
