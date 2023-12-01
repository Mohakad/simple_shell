#include "shell.h"
/**
 * my_fork- fork
 *@arg: arg
 *@argv: argv
 *@env: environment
 *@usrinp: user inp
 *@mypid: process
 *@new: new test
 *Return: 0
 */
int my_fork(char **arg, char **argv, char **env, char *usrinp, int mypid, int new)
{
	pid_t child;

	int status;

	char *fmt = "%s: %d: %s: not found\n";

	child = fork();
	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, fmt, argv[0], mypid, arg[0]);
			if (!new)
				free(arg[0]);
			free(arg);
			free(usrinp);
			exit(errno);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	}
	return (0);
}