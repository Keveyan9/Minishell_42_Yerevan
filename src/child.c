#include "minishell.h"
static void close_discriptor(t_src *data)
{
    int n;
    n = 0;
    while(n <= data->ciqel)
    { 
        close(data->pip[n] [0]);
        close(data->pip[n++] [1]);
    }
}

void child(t_src *data)
{

    if (data->ferst_child == 0 && data->pipes_count > 0)
    {
       printf("ferst_child%d__%d __%d\n",data->ferst_child,data->pipes_count,data->ciqel);
        dup2(data->pip[data->ciqel] [1],1);
        close(data->pip[data->ciqel] [0]);
        close(data->pip[data->ciqel] [1]);
       // close_discriptor(data);
       logic(data);
    }
    else if(data->ferst_child > 0 && data->pipes_count == 0)
    {
    //     //last child
        printf("last_child%d__%d __%d\n",data->ferst_child,data->pipes_count,data->ciqel);
        dup2(data->pip[data->ciqel] [0],0);
        close_discriptor(data);
    //     close(data->pip[data->ciqel-1] [0]);
    //     close(data->pip[data->ciqel-1] [1]);
    //     close(data->pip[data->ciqel] [0]);
    //     close(data->pip[data->ciqel] [1]);
         logic(data);
    }
    else
    {
        printf("next_child%d__%d __%d\n",data->ferst_child,data->pipes_count,data->ciqel);
        dup2(data->pip[data->ciqel-1] [0],0);
        dup2(data->pip[data->ciqel] [1],1);
        close(data->pip[data->ciqel-1] [0]);
        close(data->pip[data->ciqel-1] [1]);
        close(data->pip[data->ciqel] [0]);
        close(data->pip[data->ciqel] [1]);
        //close_discriptor(data);
        logic(data);
        //next child

    }

}
