#include "shell.h"
/**
 * _strtok -str to tokens
 * @str: string
 * @delim: delimit
 * Return: next tok
 **/
char *_strtok(char *str, const char *delim)
{
	static char *ptr;

	if (str)
		ptr = str;
	else if (!ptr)
		return (0);
	str = ptr + _strspn(ptr, delim);
	ptr = str + _strcspn(str, delim);
	if (ptr == str)
		return (ptr = 0);
	ptr = *ptr ? *ptr = 0, ptr + 1 : 0;
	return (str);
}
/**
 * _strcspn -max segm
 * @str1: str 1
 * @str2: str2
 * Return: leng
 **/
size_t _strcspn(const char *str1, const char *str2)
{
	size_t len = 0;

	while (*str1)
	{
		if (_strchr(str2, *str1))
			return (len);
		str1++, len++;
	}
	return (len);
}
/**
 * _strspn -initial len
 * @s1: str1
 * @s2: str delim
 * Return: length
 **/
size_t _strspn(const char *s1, const char *s2)
{
	size_t len = 0;

	while (*s1 && _strchr(s2, *s1++))
		len++;
	return (len);
}
/**
 * _strchr -first c
 * @str: string
 * @chr: character
 * Return: c loc
 **/
char *_strchr(const char *str, int chr)
{
	while (*str != (char)chr)
		if (!*str++)
			return (0);
	return ((char *)str);
}