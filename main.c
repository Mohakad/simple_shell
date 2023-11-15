#include "simple.h"
/**
 * main- shell
 * Return: 0
 */
int main(void)
{
	char *userinp = NULL, **comm;

	size_t len = 0;
	
	ssize_t nread;

	FILE *stream = stdin;

	while (1)
	{
		printf(PROMPT);
		nread = getline(&userinp, &len, stream);
		if (nread == -1)
			break;
		userinp[nread - 1] = '\0';
		if (strcmp(userinp, "") == 0)
			continue;
		comm = tocmd(userinp);
		simp_exec(comm[0], comm);
		free(comm);
	}
	free(userinp);
	return (0);
}
