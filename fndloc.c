#include "shell.h"
/**
 * fnd_pathv- path
* @env: enviroment 
* @arg: args
 * Return: path
 */
int fnd_pathv(char **arg, char **env)
{
	size_t vlu, cmd;

	struct stat inputp;

	char *token = NULL, *abspth = NULL, *pathlst = NULL;

	if (stat(*arg, &inputp) == 0)
		return (-1);
	pathlst = fnd_path(env);
	if (!pathlst)
		return (-1);
	token = _strtok(pathlst, ":");
	cmd =strn_leng(*arg);
	while (token)
	{
		vlu =strn_leng(token);
		abspth = malloc(sizeof(char) * (vlu + cmd + 2));
		if (!abspth)
		{
			free(pathlst);
			return (-1);
		}
		abspth = str_cpy(abspth, token);
		_stcat(abspth, "/");
		_stcat(abspth, *arg);

		if (stat(abspth, &inputp) == 0)
		{
			*arg = abspth;
			free(pathlst);
			return (0);
		}
		free(abspth);
		token = _strtok(NULL, ":");
	}
	free(pathlst);
	return (-1);
}