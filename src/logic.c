#include "minishell.h"

void logic(t_src *data)
{
    
    file_discriptor(data);
    change_fd(data);
    if(data->cl_in->in_fd > 0)
    {
        close(data->cl_in->in_fd);
    }
   	if(data->cl_in->out_fd > 0)
    {
        close(data->cl_in->out_fd);
    }
    if (chek_coll_builtin(data) == 0);
    else
        coll_comands(data);
}
