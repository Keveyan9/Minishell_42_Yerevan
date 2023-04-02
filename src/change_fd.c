#include "minishell.h"

void change_fd(t_src *data)
{
    if(data->cl_in->pip_her_doc[1]> 0)
    {
        printf("out_1\n");
        dup2(data->cl_in->pip_her_doc[1],1);
    }
    if(data->cl_in->pip_her_doc[0] > 0)
    {
        printf("input_0)\n");
        dup2(data->cl_in->pip_her_doc[0],0);
    }
}