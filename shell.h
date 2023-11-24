#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_LINE 1024
extern char **environ;
#define DELIM " \t\n"
/*string*/
char *shl_strcat(char *dest, char *src);
int shl_strcmp(char *str1, char *str2);
char *shl_strcpy(char *str2, char *str1);
int shl_strlen(char *str);
char *shl_strdup(const char *str);
char *getln(FILE *fl, size_t *len, size_t *n);
void tokenize(char *line, char **args);
void execute(char *command, char **args);

#endif
