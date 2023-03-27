#include "minishell.h"

void change_fd(t_src *data)
{
    if(data->cl_in->out_fd > 0)
    {
         printf("work dup2(out0)\n");
        dup2(data->cl_in->out_fd,1);
    }
    if(data->cl_in->in_fd > 0)
    {
        printf("work dup2(input1)\n");
        dup2(data->cl_in->in_fd,0);
    }
}