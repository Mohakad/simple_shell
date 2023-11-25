#include "shell.h"
/**
 * main- shell
 * @argc: argc
 * @argv: args
 * Return: 0
 */
int main(int argc, char *argv[]) {
  const char *delim = " \n";
  int notk = 0, status, i;
  char *usrinpcp = NULL, *token, *com = NULL;
  pid_t pid;

  char *buffer = NULL;
  size_t bufsize = 0;
  ssize_t ch;
char **argv_alloc = malloc(sizeof(char *) * bufsize);
  (void)argc;

  
  

  while (1) {
    if (isatty(STDIN_FILENO))
      write(STDOUT_FILENO, "$ ", 2);

    ch = getline(&buffer, &bufsize, stdin);

    if (ch == -1) {
      if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "\n", 1);
      return (-1);
    }

    usrinpcp = malloc(sizeof(char) * ch);
    if (usrinpcp == NULL) {
      perror(argv[0]);
      return (-1);
    }
    strcpy(usrinpcp, buffer);

    if (com == NULL)
      com = argv[0];

    token = strtok(usrinpcp, delim);

    notk = 0;
    while (token != NULL) {
      notk++;
      token = strtok(NULL, delim);
    }

    argv_alloc[notk] = NULL;

    notk++;

    token = strtok(buffer, delim);

    for (i = 0; token != NULL; i++) {
      argv_alloc[i] = malloc(sizeof(char) * strlen(token));
      strcpy(argv_alloc[i], token);

      token = strtok(NULL, delim);
    }

    pid = fork();
    if (pid == 0) {
      if (execve(buffer, argv_alloc, NULL) == -1) {
        perror(com);
        exit(1);
      }
    } else if (pid > 0) {
      wait(&status);
    } else {
      perror("fork");
      exit(1);
    }

    free(usrinpcp);
  }

  
  for (i = 0; argv_alloc[i] != NULL; i++) {
    free(argv_alloc[i]);

  }
  free(argv_alloc);
free(com);
  free(buffer);

  return (0);
}
