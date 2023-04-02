#include "minishell.h"

// void dolar_change(t_env *env , char *key, int n)
// {
//     t_env *plase_key;

//     plase_key = find_env(env, &(key[n]));
//     if(!plase_key)
//     {
//         free(*key);
//         key =ft_strdup("\n");
//     }
//     else
//     {
//         free(*key);
//         key = ft_strdup(plase_key->value);
//     }
//     return;
// }

void dolar_change(t_env *env , char **key, int n)
{
    t_env *plase_key;

    plase_key = find_env(env,&((*key)[n]));
    if(!plase_key)
    {
        free(*key);
        *key =ft_strdup("\n");
    }
    else
    {
        free(*key);
        *key = ft_strdup(plase_key->value);
    }
    return;
}