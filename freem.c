#include "shell.h"
/**
 * freem- free memory
 * @arg: to be free
 */
void freem(char **arg)
{
	int ind;

	if (!arg)
		return;
	for (ind = 0; arg[ind]; ind++)
	{
		free(arg[ind]);
		arg[ind] = NULL;
	}
	free(arg);
	arg = NULL;
}
