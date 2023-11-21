#include "shell.h"
/**
 * main- no argumen
 * @ac: argc
 * @argv: argv
 * Return: 0 or error
 */
int main(int ac, char **argv)
{
	char *usrinp = NULL, **comm = NULL;

	int st = 0;
	(void) ac;

	while (1)
	{
		usrinp = read_ln();
		if (usrinp == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (st);
		}
		comm = toki(usrinp);
	if (!comm)
		continue;


	st = _execute(comm, argv);
	}
}
