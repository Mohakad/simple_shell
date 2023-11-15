#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main- no argumen
 * Return: 0 or error
 */
int main(void)
{
	char usrinpt[100], *args[2];

	pid_t pid;

	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(usrinpt, 100, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		/*usrinpt[strcspn(usrinpt, "\n")] = 0;*/
		args[0] = usrinpt;
		args[1] = NULL;
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			execve(usrinpt, args, NULL);
			perror("./shell");
			exit(1);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
