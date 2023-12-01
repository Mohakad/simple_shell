#include "shell.h"
/**
 * my_getl- get user input
 * Return: usr input
 */
char *my_getl(void)
{
	char *usrinp = NULL;

	size_t n = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	if (getline(&usrinp, &n, stdin) == -1)
	{
		free(usrinp);
		return (NULL);
	}

	return (usrinp);
}