#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
#define PROMPT "> "
#define COMM_LENGTH 1024
#define ARG_S 100
char **newtok(ssize_t nofch, char *usrinp);
void execmd(char **argv);
char *shl_strcat(char *dest, char *src);
int shl_strcmp(char *str1, char *str2);
char *shl_strcpy(char *str2, char *str1);
void executer(char *userinpt);
void executer2(char **args);
void tokniz(char *userinpt, char **args);
char *get_path(char *command);
#endif
