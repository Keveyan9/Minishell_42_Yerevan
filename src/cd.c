#include "minishell.h"

static void  cd_half(t_src *data)
{
     t_env *oldpwd;
    t_env *pwd;
    t_env *origin;
    static int pwd_flag;
    
        oldpwd = find_env(data->env, "OLDPWD");
        pwd = find_env(data->env, "PWD");
        if (oldpwd)
        {
            free(oldpwd->value);
            oldpwd->value = NULL;
            if (pwd)
                oldpwd->value = pwd->value;
        }
        else if (!pwd_flag && pwd)
        {
            pwd_flag = 1;
            origin = new_node(data->env);
            origin->key = ft_strdup("OLDPWD");
            origin->value = pwd->value;
            origin->flag = 0;
        }
        if (pwd)
            pwd->value = getcwd(NULL, 0);
}

void cd(t_src *data)
{
    char *error_string;
 

    if (data->cl_in->word[2])
    {
        ft_printf("cd : too many arguments");
        data->error = 1;
        return;
    }
    data->error = chdir(data->cl_in->word[1]);
    if (data->error == 0)
        cd_half(data);
    else if (data->cl_in->word[1])
    {
        error_string = ft_strjoin("minishell: cd: ", data->cl_in->word[1]);
        perror(error_string);
        free(error_string);
    }
}