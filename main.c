#include "shell.h"
/**
 * main- shell
 * @argc: argc
 * @argv: args
 * Return: 0
 */
int main(int argc, char *argv[])
{
	const char *delim = " \n";

	int notk = 0, status, i;

	char *usrinpcp = NULL, *token, *com = NULL, *buffer = NULL;

	pid_t pid;

	size_t bufsize = 0;

	ssize_t ch;

	char **arg = malloc(sizeof(char *) * bufsize);

	(void)argc;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		ch = getline(&buffer, &bufsize, stdin);
		if (ch == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (-1);
		}
		usrinpcp = malloc(sizeof(char) * ch);
		if (usrinpcp == NULL)
		{
			perror("argv[0]");
			return (-1);
		}
		strcpy(usrinpcp, buffer);
		if (com == NULL)
			com = argv[0];
		token = strtok(usrinpcp, delim);
		notk = 0;
		while (token != NULL)
		{
			notk++;
			token = strtok(NULL, delim);
		}
		arg[notk] = NULL;
		notk++;
		token = strtok(buffer, delim);
		for (i = 0; token != NULL; i++)
		{
			arg[i] = malloc(sizeof(char) * strlen(token));
			strcpy(arg[i], token);
			token = strtok(NULL, delim);
		}
		pid = fork();
		if (pid == 0)
		{
			if (execve(buffer, arg, NULL) == -1)
			{
				perror(com);
				exit(1);
			}
		}
		else if (pid > 0)
		{
			wait(&status);
		}
		else
		{
			perror("fork");
			exit(1);
		}
		free(usrinpcp);
	for (i = 0; arg[i] != NULL; i++)
        {
                free(arg[i]);
        }
	
	}
	for (i = 0; arg[i] != NULL; i++)
	{
		free(arg[i]);
	}
	free(arg);
	free(token);
	arg = NULL;
	free(com);
	free(buffer);
	return (0);
}
