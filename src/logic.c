
#include "../inc/minishell.h"

void logic(t_src *data)
{    
    file_discriptor(data);
    change_fd(data);
    if(data->cl_in->pip_her_doc[1] > 0)
    {
        close(data->cl_in->pip_her_doc[1]);
    }
   	if(data->cl_in->pip_her_doc[0] > 0)
    {
        close(data->cl_in->pip_her_doc[0]);
    }
    if (chek_coll_builtin(data) == 0);
    else
        coll_comands(data);
    //while(1);
}
