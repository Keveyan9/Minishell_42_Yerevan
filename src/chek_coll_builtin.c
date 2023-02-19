#include "minishell.h"

int chek_coll_builtin(t_src *data)
{
    int  len;

    len = ft_strlen(data->cl_in->id);
    if(!ft_strncmp(data->cl_in->id,"echo",len))
    {
        echo(data);
        return(0);
    }
    else if (!ft_strncmp(data->cl_in->id,"cd",len))
    {
        cd(data);
        return(0);
    }else if (!ft_strncmp(data->cl_in->id,"pwd",len))
    {
        pwd();
        return(0);
    }else if (!ft_strncmp(data->cl_in->id,"export",len))
    {
        export(data);
        return(0);
    }else if (!ft_strncmp(data->cl_in->id,"unset",len))
    {
        unset(data);
        return(0);
    }else if (!ft_strncmp(data->cl_in->id,"env",len))
    {
        env_f(data);
        return(0);
    }else if (!ft_strncmp(data->cl_in->id,"exit",len))
    {
        printf("#############exit############\n");
        return(0);
    }
    else
        return(1);
}
