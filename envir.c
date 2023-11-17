#include "shell.h"
/**
 * envir- print environment
 */
void envir(void)
{
	char **envp = environ;

	while (*envp != NULL)
	{
		printf("%s\n", *envp);
		envp++;
	}
	exit(0);
}
