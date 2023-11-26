#include "shell.h"
/**
 * main- shell
 * @argc: argc
 * @argv: args
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *getl = NULL, **cmd = NULL;

	int s = 0;

	(void)argc;
	while (1)
	{
		getl = readln();
		if (getl == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (s);
		}
		cmd = tokenize(getl);
		if (!cmd)
			continue;
		s = execute(cmd, argv);

	}
}
