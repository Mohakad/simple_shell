#include "shell.h"
/**
 * main- shell
 * @argc: argc
 * @argv: args
 * Return: 0
 */
int main(int argc, char *argv[])
{
	pid_t pid;

	char *buffer;

	size_t bufsize = 1024;

	int ch;

	(void)argc;
	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror(argv[0]);
		exit(1);
	}
	while (1)
	{
		printf("$ ");
		ch = getline(&buffer, &bufsize, stdin);
		if (ch == -1)
		{
			printf("\n");
			break;
		}
		buffer[ch - 1] = '\0';
		pid = fork();
		if (pid == -1)
		{
			perror(argv[0]);
			exit(1);
		}
		else if (pid == 0)
		{
			if (execve(buffer, argv, NULL) == -1)
			{
				perror(argv[0]);
				free(buffer);
				exit(1);
			}
		}
		else
			wait(NULL);
	}
	free(buffer);
	return (0);
}
