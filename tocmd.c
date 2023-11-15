#include "simple.h"
/**
 * tocmd- split to command
 * @userinp: user input
 * Return: commands
 */
char **tocmd(char *userinp)
{
	char *token;

	int i;

	struct shell_s comm;

	comm.argc = 1;
	token = strtok(userinp, " ");

	while (token != NULL)
	{
		comm.argc++;
		token = strtok(NULL, " ");
	}
	comm.args = malloc(comm.argc * sizeof(char *));
	if (comm.args == NULL)
	{
		perror("malloc");
		exit(1);
	}
	token = strtok(userinp, " ");
	while (token != NULL)
	{
		comm.args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	comm.name = comm.args[0];
	return (comm);
}
