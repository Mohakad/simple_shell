#include "shell.h"
/**
 * main- no argumen
 * @ac: argc
 * @argv: argv
 * Return: 0 or error
 */
int main(int ac, char **argv)
{
	char *usrinp = NULL, *usrinp2 = NULL; /**newln = "\n", *token;*/

	ssize_t nofch;
	size_t nob = 0;

	int noftk = 0;
	(void)ac;
	while (1)
	{
		printf("$ ");
		nofch = getline(&usrinp, &nob, stdin);
		if (nofch == -1)
		{
			printf("\n");
			return (-1);
		}
		else
		{
			argv = malloc(sizeof(char *) * noftk);
			argv = newtok(nofch, usrinp);
			execmd(argv);
		}
	}
	free(usrinp2), free(usrinp);
	return (0);
}
