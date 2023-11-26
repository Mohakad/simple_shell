#include "shell.h"
/**
 * tokenize- toknizer
 * @inp: user inp
 * Return: toknized
 */
char **tokenize(char *inp) 
{
	char *token = NULL, *inpcop = NULL, **cmd = NULL;

	int i = 0, coun = 0;

	if (!inp)
		return (NULL);
	inpcop = shl_strdup(inp);
	token = strtok(inpcop, DELIM);
	while (token)
	{
		token = strtok(NULL, DELIM);
		coun++;
	}
	free(inpcop), inpcop = NULL;
	cmd = malloc(sizeof(char *) * (coun + 1));
	if (!cmd)
	{
		free(inp);
		inp = NULL;
		return (NULL);
	}
	token = strtok(inp, DELIM);
	while (token)
	{
		cmd[i] = shl_strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(inp), inp = NULL;
	return (cmd);
}
