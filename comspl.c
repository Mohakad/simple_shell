#include "main.h"
/**
 * comspl- split
 * @str: stri
 * Return: com
 */
char **comspl(char *str)
{
	int bufsize = BUFSIZE, pos = 0;

	char **tok1 = malloc(bufsize * sizeof(char *)), *tok2;

	if (!tok1)
	{
		fprintf(stderr, "Error\n");
		exit(EXIT_FAILURE);
	}
	tok2 = strtok(str, SEPAR);
	while (tok2 != NULL)
	{
		tok1[pos] = tok2;
		pos++;
		if (pos >= bufsize)
		{
			bufsize += BUFSIZE;
			tok1 = realloc(tok1, bufsize * sizeof(char *));
			if (!tok1)
			{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		tok2 = strtok(NULL, SEPAR);
	}
	tok1[pos] = NULL;
	return (tok1);
}
