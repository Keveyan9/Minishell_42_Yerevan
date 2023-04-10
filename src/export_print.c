#include "../inc/minishell.h"

void    print_export(t_src *data)
{
    t_env    *tmp;
    t_env    *tmp1;
    int        c;

    c = 'A';
    tmp = data->env;
    tmp1 = tmp;
	
    while (c <= 'Z')
    {
        while (tmp)
        {
            if (tmp->key[0] == (char)c && tmp->flag_p == 0)
            {
                printf("declare -x %s=%s\n", tmp->key, tmp->value);
                tmp->flag_p = 1;
            }
        tmp = tmp->next;
        }
        tmp = tmp1;
        c++;
    }
	tmp = data->env;
	while(tmp)
	{
		tmp->flag_p = 0;
		tmp = tmp->next;
	}
	
}