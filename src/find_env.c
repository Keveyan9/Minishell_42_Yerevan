#include"minishell.h"

t_env   *find_env(t_env *env,char *s)
{
    while(env)
    {
        if (ft_strncmp(s,env->key,ft_strlen(s)) == 0)
            return(env);
        env = env->next;
    }
    return(NULL);
}



