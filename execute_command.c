#include "main.h"
/**
 *execute_command- command excute
 *@command: command
 *Return: 0 or 1
 */
void execute_command(command_t *command)
{
	/*char *args[] = { NULL };*/

	int status;

	pid_t child_pid = fork();

	if (child_pid < 0)
	{
		perror("fork");
		return;
	}
	if (child_pid == 0)
	{
		execve(command->name, NULL, NULL);
		perror("execve");
		exit(1);
	}
	wait(&status);
	if (status != 0)
		printf("The command '%s' exited with status %d.\n", command->name, status);
}
