#include "shell.h"
void freea(char **com)
{
   /* int i;*/
    if (!com)
	    return;
   /**for (i =0; com[i] != '\n'; i++)
*	{
*		free(com[i]);
*		com[i] = NULL;
*	}*/
	free(com), com = NULL;
}
