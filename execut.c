#include "simple.h"
/**
 * simp_exec- execute commands
 * @command: commands to run
 * @args: num of args
 */
void simp_exec(char *command, char **args)
{
	pid_t pid;

	int status;

	if (strcmp(command, "exit") == 0)
		exit(0);
	else
	{
		pid = fork();
		if (pid == -1)
			perror("fork");
		else if (pid == 0)
		{
			if (execvp(command, args) == -1)
			{
				perror("exec");
				exit(1);
			}
			else
				waitpid(pid, &status, 0);
		}
	}
}
