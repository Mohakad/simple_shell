#include "shell.h"
/**
 * main- no argumen
 * @ac: argc
 * @argv: argv
 * Return: 0 or error
 */
int main(int ac, char **argv)
{
	char *usrinp = NULL, *usrinp2 = NULL, *newln = "\n", *token;

	ssize_t nofch;
	size_t nob = 0;

	int noftk = 0, i;

	(void)ac;
	while (1)
	{
		printf("$ ");
		nofch = getline(&usrinp, &nob, stdin);
	if (nofch == -1)
	{
		return (-1);
	}
	usrinp2 = malloc(sizeof(char) * nofch);
	if (usrinp2 == NULL)
	{
		perror("shell: memory error");
		return (-1);
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
	execmd(argv);
	}
	free(usrinp2), free(usrinp);
	return (0);
}
