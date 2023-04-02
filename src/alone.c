#include "minishell.h"

static int is_builtin(t_src *data)
{
  
	if (ft_strlen(data->cl_in->word[0]) == 4 && ft_strncmp(data->cl_in->word[0], "echo", 4) == 0)
		return (1);
	else if ( ft_strlen(data->cl_in->word[0]) == 2 && ft_strncmp(data->cl_in->word[0], "cd", 2) == 0)
		return (1);
	else if (ft_strlen(data->cl_in->word[0]) == 3 && ft_strncmp(data->cl_in->word[0], "pwd", 3) == 0)
		return (1);
	else if (ft_strlen(data->cl_in->word[0]) == 6 && ft_strncmp(data->cl_in->word[0], "export",6) == 0 )
		return (1);
	else if (ft_strlen(data->cl_in->word[0]) == 5 && ft_strncmp(data->cl_in->word[0], "unset", 5) == 0 )
		return (1);
	else if (ft_strlen(data->cl_in->word[0]) == 3 && ft_strncmp(data->cl_in->word[0], "env", 3) == 0 )
		return (1);
	else if (ft_strlen(data->cl_in->word[0]) == 4 && ft_strncmp(data->cl_in->word[0], "exit", 4) == 0)
		return (1);;
	 return (0);
}

void alone(t_src *data)
{
    if(is_builtin(data))
    {
        file_discriptor(data);
		if(!g_flags)
		{
			change_fd(data);
			chek_coll_builtin(data);
			close_herdoq_fd(data);
			if(data->cl_in->pip_her_doc[0] > 0 /* && printf("alone")*/)
			{	
				dup2(data->main_fd_in,0);
				close(data->cl_in->pip_her_doc[0]);
			}
			if(data->cl_in->pip_her_doc[1] > 0)
			{
				dup2(data->main_fd_out,1);
				close(data->cl_in->pip_her_doc[1]);
			}
		}
    }
    else
		alone_child(data);
}