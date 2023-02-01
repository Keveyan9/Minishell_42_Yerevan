#include "minishell.h"

void cd(t_src *data)
{
    char    *error_string;
    t_env   *oldpwd;
    t_env   *pwd;
    t_env   *origin;
    char    **s;

    s = ft_split(data->token_list->token,' ');
    data->syntax_err = chdir(s[1]);
     if(data->syntax_err == 0)
     {
        oldpwd = find_env(data->env,"OLDPWD");
        pwd = find_env(data->env,"PWD");
     if(oldpwd && pwd)
        {
            free(oldpwd->value);
            oldpwd->value = pwd->value;
            pwd->value = getcwd(NULL,0);
        }
         else if (pwd)     
    {
        
        origin = new_node(data->env);
        origin->key = ft_strdup("OLDPWD");
        origin->value = pwd->value;
        origin->flag = 0;
        pwd->value = getcwd(NULL,0);
    }    
    }
    else if (s[1])
    {
        error_string = ft_strjoin("minishell: cd: ",s[1]);
        perror(error_string);
        free(error_string);       
     }
    frik(s);
} 
