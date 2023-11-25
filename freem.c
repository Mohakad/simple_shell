#include "shell.h"
/**
 * freem- free memory
 * @arg: to be free
 */
void freem(char **arg)
{
	int i;

	if (arg)
	{
		for (i = 0; arg[i] != NULL; i++)
			free(arg[i]);
		free(arg);
		arg = NULL;
	}
}
