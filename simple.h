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

struct shell_s {
	char **args;
	int argc;
	char *name;
}

#define BUFFSIZE (1024)
#define PROMPT ("$ ")
#define DELIM (" \t\r\n\a")
char *tocmd(char *userinp);
void simp_exec(struct shell_s comm);
#endif
