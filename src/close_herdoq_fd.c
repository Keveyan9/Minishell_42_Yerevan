#include "minishell.h"

void close_herdoq_fd(t_src *data)
{
    data->cl_in = data->clin_head;
    while (data->cl_in)
    {
        if(data->cl_in->in_fd > 0)
        {
    		close(data->cl_in->in_fd);
        }
   		if(data->cl_in->out_fd > 0)
        {
        	close(data->cl_in->out_fd);
        }
        data->cl_in = data->cl_in->next;
    }
    data->cl_in = data->clin_head;
}