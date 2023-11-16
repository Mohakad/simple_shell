#include "main.h"
/**
 * main- main
 * @argc: argc
 * @argv: argv
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *comm, **usrinp;

	int exe_com;

	(void)argc;
	(void)argv;
	do {
		printf("> ");
		comm = readinp();
		usrinp = comspl(comm);
		exe_com = executer(usrinp);
		free(comm);
		free(usrinp);
	} while (exe_com);
	return (0);
}

