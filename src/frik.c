#include "minishell.h"

void frik(char **s1)
{
	int i;

	i = 0;
	if (s1)
	{
		while (s1[i])
			free(s1[i++]);
		free(s1);
	}
}
