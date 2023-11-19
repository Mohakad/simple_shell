#include "shell.h"
/**
 * shl_strdup- str dp
 * @str: string
 * Return: pointer
 */
char *shl_strdup(const char *str)
{
	int l = 0, i;

	char *p;
	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		str++;
		l++;
	}
	str -= l;
	p = malloc(sizeof(char) * (l + 1));
	if (p == NULL)
	{
		free(p);
		return (NULL);
	}
	for (i = 0; i <= l; i++)
		p[i] = str[i];
	return (p);
}

/**
 * shl_strlen- calc length of str
 * @str: string
 * Return: length
 */
int shl_strlen(char *str)
{
	unsigned long int len = 0;

	if (!str)
		return (0);

	while (*str++)
		len++;
	return (len);
}
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

/**
 * shl_strcat - combine src to dest
 * @dest: destination
 * @src: src
 * Return: dest
 */
char *shl_strcat(char *dest, char *src)
{
	char *comb = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (comb);
}
