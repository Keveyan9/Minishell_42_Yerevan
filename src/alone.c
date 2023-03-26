#include "minishell.h"

static int is_builtin(t_src *data)
{
  
	if (ft_strlen(data->cl_in->id) == 4 && ft_strncmp(data->cl_in->id, "echo", 4) == 0)
		return (1);
	else if ( ft_strlen(data->cl_in->id) == 2 && ft_strncmp(data->cl_in->id, "cd", 2) == 0)
		return (1);
	else if (ft_strlen(data->cl_in->id) == 3 && ft_strncmp(data->cl_in->id, "pwd", 3) == 0)
		return (1);
	else if (ft_strlen(data->cl_in->id) == 6 && ft_strncmp(data->cl_in->id, "export",6) == 0 )
		return (1);
	else if (ft_strlen(data->cl_in->id) == 5 && ft_strncmp(data->cl_in->id, "unset", 5) == 0 )
		return (1);
	else if (ft_strlen(data->cl_in->id) == 3 && ft_strncmp(data->cl_in->id, "env", 3) == 0 )
		return (1);
	else if (ft_strlen(data->cl_in->id) == 4 && ft_strncmp(data->cl_in->id, "exit", 4) == 0)
		return (1);;
	 return (0);
}

void alone(t_src *data)
{
    if(is_builtin(data))
    {
        file_discriptor(data);
		data->main_fd_in = dup(0);
		data->main_fd_out = dup(1);
		change_fd(data);
    	chek_coll_builtin(data);
		if(data->cl_in->in_fd > 0)
		{	
			dup2(data->main_fd_in,0);
			close(data->cl_in->in_fd);
		}
		if(data->cl_in->out_fd)
		{
			dup2(data->main_fd_out,1);
			close(data->cl_in->out_fd);
		}
    }
    else
        alone_child(data);
}