#ifndef SIMPLE_H
#define SIMPLE_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

#define BUFFSIZE (1024)
#define PROMPT ("$ ")
#define DELIM " \t\r\n\a"
char **spliter(char *line);
char *user_inp(void);
int executer(char **args);
#endif
