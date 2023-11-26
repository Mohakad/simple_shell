#include "shell.h"
/**
 * readln- get input
 * Return: input
 */
char *readln(void)
{
	char *inp = NULL;

	ssize_t sst;

	size_t st = 0;

	write(STDOUT_FILENO, "$ ", 2);
	sst = getline(&inp, &st, stdin);
	if (sst == -1)
	{
		free(inp);
		return (NULL);
	}	
	return (inp);
}
