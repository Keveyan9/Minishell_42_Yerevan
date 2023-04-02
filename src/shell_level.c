#include "minishell.h"

void    shell_level(t_src *data, char ** av)
{
    t_env *shlvl;
    int i;
     
    i = 0;
    if ( av[1] && av[1][0] == '1' && !av[1][1])
    {   
        shlvl = find_env(data->env,"SHLVL");
        i = ft_atoi(shlvl->value) + 1;
        free(shlvl->value);
        shlvl->value = ft_itoa(i);
    }
}