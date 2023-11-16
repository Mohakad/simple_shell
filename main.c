#include "main.h"
/**
 * main- no argumen
 * Return: 0 or error
 */
int main(void)
{
	char usrinpt[COMM_LENGTH], **env = environ;

	while (1)
	{
		printf("($) ");
		if (fgets(usrinpt, COMM_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		if (shl_strcmp(usrinpt, "exit") == 0)
			break;
		if (strcmp(usrinpt, "env") == 0)
		{
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
			continue;
		}
		executer(usrinpt);
	}
	return (0);
}
