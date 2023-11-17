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

	int noftk = 0, i, j;

	usrinp2 = malloc(sizeof(char) * nofch);
	if (usrinp2 == NULL)
	{
		return (NULL);
	}
	shl_strcpy(usrinp2, usrinp);
	token = strtok(usrinp, newln);
	while (token != NULL)
	{
		noftk++;
		token = strtok(NULL, newln);
	}
	noftk++;
	argv = malloc(sizeof(char *) * noftk + 1);
	if (!argv)
		return (NULL);
	token = strtok(usrinp2, newln);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		if (!argv[i])
		{
			for (j = 0; j < i; j++)
				free(argv[j]);
			free(argv);
			return (NULL);
		}
		shl_strcpy(argv[i], token);
		token = strtok(NULL, newln);
	}
	argv[i] = NULL;
	free(usrinp2);
	return (argv);
}
