#include "shell.h"
/**
 *_stcat- concat str
 *@dest: dest
 *@src: sorce
 *Return: dest
 */
char *_stcat(char *dest, char *src)
{
	int id = 0;
	int is = 0;

	while (dest[id] != '\0')
		id++;
	while (src[is] != '\0')
	{
		dest[id] = src[is];
is++;		
id++;
	}
	dest[id] = '\0';
	return (dest);
}
/**
 *strn_leng - length of s
 * @s: str
 * Return: length
 */

int strn_leng(char *s)
{
	int ln = 0;

	while (*(s + ln) != '\0')
	{
		ln++;
	}

	return (ln);
}
/**
 * str_cmp - compare 2 str
 * @s1: str 1
 * @s2: str 2
 * Return: 0
 */

int str_cmp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] != '\0' && s2[a] != '\0'; a++)
	{
		if (s1[a] != s2[a])
			return ((int)s1[a] - s2[a]);
	}
	return (0);
}
/**
 *strn_cmp - compares two strings.
 *@s1: str 1
 *@s2: str 2
 *@n: str count
 * Return: diff
 */
size_t strn_cmp(char *s1, char *s2, size_t n)
{
	size_t i, j;

	for (j = 0; s1[j] != '\0' && j < n; j++)
	{
		i = s1[j] - s2[j];

		if (i != 0)
		{
			return (i);
		}
	}
	return (0);
}
/**
 * str_cpy - copie src to dest
 * @dest: dest
 * @src: sourc
 * Return: dest
 */
char *str_cpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		++i;
	}
	*(dest + i) = *(src + i);

	return (dest);
}