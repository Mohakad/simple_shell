#include "shell.h"
/**
 * m_exit- close
 * @arg: arg
 * @_exit: exit valu
 * @usrinp: input 
 */
void m_exit(char **arg, char *usrinp, int _exit)
{
	int status = 0;

	if (!arg[1])
	{
		free(usrinp);
		free(arg);
		exit(_exit);
	}
	status = atoi(arg[1]);
	free(usrinp);
	free(arg);
	exit(status);
}