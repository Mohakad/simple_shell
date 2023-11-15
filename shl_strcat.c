#include "main.h"
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
