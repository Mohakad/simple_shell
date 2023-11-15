#include "simple.h"
/**
 * tocmd- split to command
 * @userinp: user input
 * Return: commands
 */
char **tocmd(char *userinp)
{
	int argc = 1, i = 0;

	char *token, **comm;

	token = strtok(userinp, " ");

	while (token != NULL)
	{
		token = strtok(NULL, " ");
		argc++;
	}
	comm = malloc(argc * sizeof(char *));
	if (comm == NULL)
	{
		perror("malloc");
		exit(1);
	}
	token = strtok(userinp, " ");
	while (token != NULL)
	{
		comm[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	return (comm);
}
