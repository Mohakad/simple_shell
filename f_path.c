#include "shell.h"
/**
 * fnd_path- PATH finder
 * @env: environment
 * Return: path
 */
char *fnd_path(char **env)
{
	char *path = NULL;

	size_t var = 0, times = 5;
	
	int i;

	for (i = 0; strn_cmp(env[i], "PATH=", 5); i++)
		;
	if (env[i] == NULL)
		return (NULL);
	for (times = 5; env[i][var]; var++, times++)
		;
	path = malloc(sizeof(char) * (times + 1));
	if (path == NULL)
		return (NULL);
	for (var = 5, times = 0; env[i][var]; var++, times++)
		path[times] = env[i][var];
	path[times] = '\0';
	return (path);
}
