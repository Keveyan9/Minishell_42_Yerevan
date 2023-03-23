#include "minishell.h"

void change_fd(t_src *data)
{
    if(data->cl_in->in_fd > 0)
        dup2(data->cl_in->in_fd,0);
    if(data->cl_in->out_fd > 0)
        dup2(data->cl_in->out_fd,1);
}