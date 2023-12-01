#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;
/*strings*/
char *_stcat(char *dest, char *src);
int strn_leng(char *s);
char *str_cpy(char *dest, char *src);
int str_cmp(char *s1, char *s2);
size_t strn_cmp(char *s1, char *s2, size_t n);
/*func*/
char *_strchr(const char *s, int c);
size_t _strspn(const char *s1, const char *s2);
size_t _strcspn(const char *s1, const char *s2);
int _putchar(char c);
char *_strtok(char *str, const char *delim);
char *fnd_path(char **env);
int fnd_pathv(char **arg, char **env);
void _getenv(char **env);
char *my_getl(void);
char **toknizz(char *lineptr);
void m_exit(char **args, char *lineptr, int n);
int my_fork(char **arg, char **argv, char **env,
char *usrinp, int mypid, int new);

#endif
