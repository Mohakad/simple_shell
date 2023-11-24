#include "shell.h"
/**
 * main- shell
 * @argc: argc
 * @argv: args
 * Return: 0
 */
int main(int argc, char *argv[])
{
	const char *delim = " \n";
    int notk = 0, i, status;
    char *usrinpcp = NULL, *token;
	pid_t pid;

	char *buffer = NULL;

	size_t bufsize = 1024;

	ssize_t ch;

	(void)argc;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		ch = getline(&buffer, &bufsize, stdin);
		if (ch == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (-1);
		}
		usrinpcp = malloc(sizeof(char) * ch);
          if (usrinpcp == NULL)
          {
                  perror(argv[0]);
                  return (-1);
	  }
	  strcpy(usrinpcp, buffer);


        token = strtok(usrinpcp, delim);

        while (token != NULL){
            notk++;
            token = strtok(NULL, delim);
        }
        notk++;


        argv = malloc(sizeof(char *) * notk);


        token = strtok(buffer, delim);

        for (i = 0; token != NULL; i++){
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;
		pid = fork();
		if (pid == 0) {

   if (execve(argv[0], argv, NULL) == -1) {
        perror(argv[0]);
        exit(1);
      }
    } 
	else if (pid > 0) 
      wait(&status);
	 else {
      perror("fork");
      exit(1);
    }
	}
	free(buffer);
	free(usrinpcp);
	free(argv);
	return (0);
}
