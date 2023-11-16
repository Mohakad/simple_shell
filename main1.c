#include "main.h"
int main(int argc, char *argv[], char *envp[])
{
	char *userinp = NULL, *args[COMM_LENGTH];

	size_t length = 0;
	
	ssize_t inp_read;
	
	int waite;
	
	pid_t pid;

    (void)argc;
    (void)argv;
	while (1) {
        printf("($) ");
        if ((inp_read = getline(&userinp, &length, stdin)) == -1)
            break;
       
        userinp[inp_read - 1] = '\0';
        args[0] = userinp;
        pid = fork();
        if (pid == 0) {
            execve(args[0], args, envp);
            perror("execve");
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else {
            waitpid(pid, &waite, 0);
        }
    }

    free(userinp);
    exit(EXIT_SUCCESS);
}
