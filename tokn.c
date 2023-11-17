#include "shell.h"
/**
 * newtok- split into comm
 * @nofch: number of char
 * @usrinp: user input
 * Return: commands or -1
 */
char **newtok(ssize_t nofch, char *usrinp)
{
	const char *newln = " \n";

	char *usrinp2 = NULL;

	char **argv = NULL, *token;

	int noftk = 0, i;

	usrinp2 = malloc(sizeof(char) * nofch);
	if (usrinp2 == NULL)
	{
		perror("tsh: memory error");
		exit(-1);
	}
	strcpy(usrinp2, usrinp);
	token = strtok(usrinp, newln);
	while (token != NULL)
	{
		noftk++;
		token = strtok(NULL, newln);
	}
	noftk++;
	argv = malloc(sizeof(char *) * noftk);
	token = strtok(usrinp2, newln);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, newln);
	}
	argv[i] = NULL;
	free(usrinp2);
	return (argv);
}
