#ifndef MAINH_H
#define MAINH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define COMM_LENGTH (1024)
#define ARG_S (20)
char *shl_strcat(char *dest, char *src);
int shl_strcmp(char *str1, char *str2);
int shl_strlen(char *str);
#endif
