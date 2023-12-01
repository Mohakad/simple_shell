#include "shell.h"
/**
 *_getenv- get envi
 *@env: env
 */

void _getenv(char **env)
{
	size_t n = 0;

	while (env[n])
	{
		write(STDOUT_FILENO, env[n],strn_leng(env[n]));
		write(STDOUT_FILENO, "\n", 1);
		n++;
	}
}
