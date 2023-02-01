#include "minishell.h"

void unset(t_src *data)
{
    t_env *cat_segment;

    cat_segment = find(data->env,data->token_list->token);
    if(cat_segment)
    {
        delet_env(cat_segment);
    }
    
}

