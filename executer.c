#include "shell.h"
/**
 * execmd- executer
 * @argv: argv
 */
void execmd(char **argv)
{
	char *command = NULL, *comm2 = NULL;

	pid_t pid;

	if (argv)
	{

		command = argv[0];
		comm2 = get_path(command);
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			if (strcmp(comm2, "exit") == 0)
				exit(0);
			if (execve(comm2, argv, NULL) == -1)
			{
			perror("Error");
			}
		}
		else
			wait(NULL);
	}
}
/**
 * executer- excute command
 * @userinpt: input
 */
void executer(char **userinpt)
{
	pid_t pid;

	char *command = NULL, *comm2 = NULL;
	
	command = userinpt[0];
	comm2 = get_path(command);
	pid = fork();
	if (strcmp(command, "exit") == 0)
		exit(0);
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(comm2, userinpt, NULL) == -1)
			printf("command not found\n");
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
