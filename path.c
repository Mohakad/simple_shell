#include "shell.h"
/**
 * get_path- find location
 * @command: user inp
 * Return: path
 */
char *get_path(char *command)
{
	char *path, *cofpath, *path_token, *file_path;

	int clen, dir_len;

	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		cofpath = strdup(path);
		clen = shl_strlen(command);
		path_token = strtok(cofpath, ":");
		while (path_token != NULL)
		{
			dir_len = strlen(path_token);
			file_path = malloc(clen + dir_len + 2);
			shl_strcpy(file_path, path_token);
			shl_strcat(file_path, "/");
			shl_strcat(file_path, command);
			shl_strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(cofpath);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(cofpath);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
