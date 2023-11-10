#include "main.h"
/**
  *shell_strcmp- compares 2 str
  *@str1: first wstr
  *@str2: 2nd
  *Return: 1 or -1
  */
int shell_strcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] < str2[i])
			return (-1);
		else if (str1[i] > str2[i])
			return (1);
		i++;
	}
	if (str2[i] == '\0' && str1[i] == '\0')
		return (0);
	else if (str1[i] == '\0')
		return (-1);
	else
		return (1);
}
