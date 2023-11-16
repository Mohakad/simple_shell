#ifndef MAINH_H
#define MAINH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

extern char **environ;
#define COMM_LENGTH (1024)
#define ARG_S (20)
char *readinp(void);
char **comspl(char *str);
int executer(char **args);
char *shl_strcpy(char *str2, char *str1); 
void executer(char *userinpt);
void tokniz(char *userinpt, char **args);
void executer2(char **args);
char *shl_strcat(char *dest, char *src);
int shl_strcmp(char *str1, char *str2);
int shl_strlen(char *str);
#endif
