#include "shell.h"
/**
 * execmd: executer
 * @argv: argv
 */
void execmd(char **argv)
{
	char *command = NULL;

	if (argv)
	{
		command = argv[0];
		if (execve(command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
/**
 * executer- excute command
 * @userinpt: input
 */
void executer(char *userinpt)
{
	pid_t pid;

	char *args[ARG_S + 1];

	tokniz(userinpt, args);
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		execv(args[0], args);
		executer2(args);
		fprintf(stderr, "userinpt not found: %s\n", args[0]);
		exit(1);
	}
	else
		wait(NULL);
}
/**
 * executer2- excuter with path
 * @args: commands
 */
void executer2(char **args)
{
	char *path2 = NULL, *tokenedp = NULL;

	char *path = getenv("PATH");

	path2 = shl_strcpy(path2, path);

	tokenedp = strtok(path2, ":");

	while (tokenedp != NULL)
	{
		char path_userinpt[COMM_LENGTH];

		shl_strcpy(path_userinpt, tokenedp);
		shl_strcat(path_userinpt, "/");
		shl_strcat(path_userinpt, args[0]);
		execv(path_userinpt, args);
		tokenedp = strtok(NULL, ":");
	}
	free(path2);
}
