#include "main.h"
/**
  *main- shell
  *Return: 0 or 1
  */
int main(void)
{
	command_t commands[] = {
		{"exit", exit},
		{NULL}
	};
	command_t *comd = NULL;

	int i = 0;

	char usrinp[1024];

	while (1)
	{
		printf("> ");
		if (fgets(usrinp, sizeof(usrinp), stdin) == NULL)
			break;
		usrinp[my_strlen(usrinp, NULL) - 1] = '\0';
		if (shell_strcmp(usrinp, "exit") == 0)
		{
			printf("Exiting the shell...\n");
			break;
		}
		while (commands[i].name != NULL)
		{
			if (shell_strcmp(usrinp, commands[i].name) == 0)
			{
				comd->name = commands[i].name;
				break;
			}
			i++;
		}
		if (comd == NULL)
			printf("nulll");
		else
			execute_command(comd);
	}
	return (0);
}
