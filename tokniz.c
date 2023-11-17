#include "shell.h"
/**
 * toknize- create token
 * @userinpt: user input
 * @args: argument
 */
void tokniz(char *userinpt, char **args)
{
	char *token = strtok(userinpt, " ");

	int i = 0;

	while (token != NULL && i < ARG_S)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
}
