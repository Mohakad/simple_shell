#include "simple.h"
/**
 * main- shell
 * Return: 0
 */
int main(void)
{
	struct shell_s comm;

	ssize_t nread;

	char *userinp = NULL;

	size_t len = 0;

	FILE *stream = stdin;

	while (1)
	{
		printf("($) ");
		nread = getline(&userinp, &len, stream);
		if (nread == -1)
			break;
		userinp[nread - 1] = '\0';
		if (strcmp(userinp, "") == 0)
			continue;
		comm = tocmd(userinp);

		simp_exec(comm);
		free(comm.args);
	}
	free(userinp);
	return (0);
}
