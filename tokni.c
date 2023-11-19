#include "shell.h"
char **toki(char *usrinp)
{
    char **comm = NULL, *token = NULL, *temp = NULL;
    int i = 0, cpt = 0;
    if (!usrinp)
    	return (NULL);
    temp = shl_strdup(usrinp);
    token = strtok(temp, DELIM);
    if (token == NULL)
    {
	
        free(temp), temp = NULL;
        free(usrinp), usrinp = NULL;
        return (NULL);
    }
    while (token)
    {
	    cpt++;
        token = strtok(NULL, DELIM);
    }
    free(temp), temp = NULL;
    comm = malloc(sizeof(char *) * (cpt + 1));
    if (!comm)
    {
        free(usrinp), usrinp = NULL;
        return (NULL);
    }
    token = strtok(usrinp, DELIM);
    while (token)
    {
        comm[i] = token;
        token = strtok(NULL, DELIM);
        i++;
    }
    
       free(usrinp), usrinp = NULL;
    comm[i] = NULL;
    return (comm);

}
