#include "shell.h"
/**
* shl_strcpy - copies
* @dest: dest
* @src: source
* Return: dest
*/
char *shl_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/**
* shl_strdup - duplicate
* @str: str
* Return: string
*/
char *shl_strdup(const char *str)
{
	int length = 0, j;

	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		str++;
		length++;
	}
	str = str - length;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (j = 0; j <= length; j++)
		ret[j] = str[j];
	return (ret);
}
