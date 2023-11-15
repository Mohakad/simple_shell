#include "main.h"
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
