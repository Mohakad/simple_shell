#include "shell.h"
/**
 * execute- executer
 * @command: toknized
 * @args: argv
 * Return: status
 */
int execute(char **command, char **args)
{
	int status;

	pid_t pid = fork();
  
	if (pid == 0)
	{
    		if (execve(command[0], command, environ) == -1) 
		{
			perror(args[0]);
			freem(command);
			exit(0);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		freem(command);
	}
	return (WEXITSTATUS(status));
}
