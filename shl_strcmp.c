#include "shell.h"
/**
 * shl_strcmp - compare str1 and str2
 * @str1: 1st str
 * @str2: 2nd str
 * Return: 0 or 1 or -1
 */
int shl_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str2++;
		str1++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}
