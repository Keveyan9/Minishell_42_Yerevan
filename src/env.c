#include "minishell.h"

void env_f(t_src *data)
{
    while(data->env)
    {
        if(data->env->value)
            printf("%s=%s\n",data->env->key,data->env->value);
        data->env = data->env->next;
    }
}
