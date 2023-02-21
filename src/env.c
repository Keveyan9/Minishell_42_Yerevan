#include "minishell.h"

void env_f(t_src *data)
{
    t_env *origin;

    origin = data->env;
    while(origin)
    {
        if(origin->value)
            printf("%s=%s\n",origin->key,origin->value);
        origin = origin->next;
    }
}
