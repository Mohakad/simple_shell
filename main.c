#include "main.h"
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
		printf("($) ");
		if (fgets(usrinpt, 100, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		usrinpt[shl_strlen(usrinpt) - 1] = '\0';
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
