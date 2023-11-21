#include "shell.h"
int _execute(char **comm, char **argv)
{
    int wait;
    pid_t npid;

    npid = fork();
    if (npid == 0)
    {
        if (execve(comm[0], comm, environ) == -1)
        {
            perror(argv[0]);
            freea(comm);
	    exit(0);
        }
    }
    else
    {
        waitpid(npid, &wait, 0);
    /*  freea(comm);*/
    }
    return (WEXITSTATUS(wait));
}
