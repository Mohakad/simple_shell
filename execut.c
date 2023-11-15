#include "simple.h"
/**
 * simp_exec- execute commands
 * @comm: commands to run
 */
void simp_exec(struct shell_s comm)
{
	int status;

	pid_t pid;

	if (strcmp(comm.name, "exit") == 0)
		exit(0);
	else if (strcmp(comm.name, "cd") == 0)
	{
		if (comm.args[1] == NULL)
			chdir(getenv("HOME"));
		else
		{
			if (chdir(comm.args[1]) != 0)
				perror("cd");
		}
	}
	else
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
		}
		else if (pid == 0)
		{
			if (execvp(comm.name, comm.args) == -1)
			{
				perror("exec");
				exit(1);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
}
