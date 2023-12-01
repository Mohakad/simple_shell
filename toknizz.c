#include "shell.h"
/**
 * toknizz - tokeniz string
 * @usrinp: user inp
 * Return: To a pointer
 */
char **toknizz(char *usrinp)
{
	char **comm = NULL, *token = NULL;

	size_t i = 0;

	int size = 0;

	if (usrinp == NULL)
		return (NULL);
	for (i = 0; usrinp[i]; i++)
	{
		if (usrinp[i] == ' ')
			size++;
	}
	if ((size + 1) ==strn_leng(usrinp))
		return (NULL);
	comm = malloc(sizeof(char *) * (size + 2));
	if (comm == NULL)
		return (NULL);

	token = _strtok(usrinp, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		comm[i] = token;
		token = _strtok(NULL, " \n\t\r");
	}
	comm[i] = NULL;
	return (comm);
}