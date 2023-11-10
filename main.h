#ifndef MAINH
#define MAINH
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
  *command_t struct - structuer
  *@name: name
  *@function: function
  */

typedef struct command_t{
	char *name;
	void (*function)();
} command_t;
int shell_strcmp(char *str1, char *str2);
void execute_command(command_t *command);
int my_strlen(char *str, int *length);
#endif
