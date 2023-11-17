#include "shell.h"
/**
 * shl_strcpy - str copy
 * @str2: to
 * @str1: from
 * Return: the copy
 */
char *shl_strcpy(char *str2, char *str1)
{
	int ind = 0;

	if (str2 == str1 || str1 == 0)
		return (str2);
	while (str1[ind])
	{
		str2[ind] = str1[ind];
		ind++;
	}
	str2[ind] = 0;
	return (str2);
}
