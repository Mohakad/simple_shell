#include "main.h"
/**
  *my_strlen- calc str length
  *@str: the str
  *@length: 0
  *Return: length
  */
int my_strlen(char *str, int *length)
{
	while (*str != '\0')
	{
		str++;
		*length += 1;
	}
	return (0);
}
