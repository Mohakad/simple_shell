#include "main.h"
/**
 * readinp- accept inputs
 * Return: str
 */
char *readinp(void)
{
	char *str = NULL;

	size_t bufsize = 0;

	getline(&str, &bufsize, stdin);
	return (str);
}
