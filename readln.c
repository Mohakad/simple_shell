#include "shell.h"
/**
 * read_ln- get input
 * Return: input
 */
char *read_ln(void)
{
	ssize_t nof;
	size_t len = 0;
	char *usrinp = NULL;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	nof = getline(&usrinp, &len, stdin);
	if (nof == -1)
	{
		free(usrinp);
		usrinp = NULL;
		return (NULL);
	}
	return (usrinp);
}
