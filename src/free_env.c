#include "minishell.h"

void free_env(t_src *data)
{
    while (data->env)
    {
        if (data->env->key)
            free(data->env->key);
        if (data->env->value)
            free(data->env->value);
        if (data->env->next != NULL)
        {
            data->env = data->env->next;
            free(data->env->prev);
        }
        else
        {
            free(data->env);
            break;
        }
    }
}
