#include "minishell.h"

void child(t_src *data)
{
 if(data->ferst_child == 0 && data->pipes_count == 0)
    {
        ft_printf("next_child%d__%d\n",data->ferst_child,data->pipes_count);
       coll_comands(data);
        oll_free(data);
    }
    else if (data->ferst_child == 0 && data->pipes_count > 0)
    {
       printf("ferst_child%d__%d\n",data->ferst_child,data->pipes_count);
        dup2(data->pip[1],1);
        close(data->pip[0]);
        close(data->pip[1]);
        logic(data);
    
    }
    else if(data->ferst_child > 0 && data->pipes_count == 0)
    {
        //last child
        printf("last_child%d__%d\n",data->ferst_child,data->pipes_count);
        dup2(data->pip[0],0);
      //  dup2(data->pip[1],1);
         close(data->pip[0]);
        close(data->pip[1]);
        logic(data);
    }
    else
    {
        dup2(data->pip[0],0);
        dup2(data->pip[1],1);
        close(data->pip[0]);
        close(data->pip[1]);
        printf("next_child%d__%d\n",data->ferst_child,data->pipes_count);
        logic(data);
        //next child

    }

}
