#include "shell.h"
/**
 * main - start shell
 * @argc:argc
 * @argv: argv
 * @env: environment
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	char *usrinp = NULL, **usrinp2 = NULL;
	int val = 0, stat = 0, n = 0;
	(void)argc;

	while (1)
	{
		usrinp = my_getl();
		if (usrinp)
		{
			val++;
			usrinp2 = toknizz(usrinp);
			if (!usrinp2)
			{
				free(usrinp);
				continue;
			}
			if ((!str_cmp(usrinp2[0], "exit")) && usrinp2[1] == NULL)
				m_exit(usrinp2, usrinp, stat);
			if (!str_cmp(usrinp2[0], "env"))
				_getenv(env);
			else
			{
				n = fnd_pathv(&usrinp2[0], env);
				stat = my_fork(usrinp2, argv, env, usrinp, val, n);
				if (n == 0)
					free(usrinp2[0]);
			}
			free(usrinp2);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(stat);
		}
		free(usrinp);
	}
	return (stat);
}