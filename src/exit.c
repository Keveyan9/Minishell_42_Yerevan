#include "minishell.h"

void exit_f(t_src *data)
{
    size_t n;

    n = 0;
    if(!data->cl_in->word[2] && data->cl_in->word[1])
    {
        while(data->cl_in->word[1][n])
            {
                if (!ft_isdigit(data->cl_in->word[1][n++]))
                {
                    printf("exit: %s: numeric argument requireds\n",data->cl_in->word[1]);
                    data->error = 2;
                    break;
                 }
            }
            if(n == ft_strlen(data->cl_in->word[1]))
                data->error = ft_atoi(data->cl_in->word[1]);
            else
                data->error = 2;
    }
    else if (data->cl_in->word[2])
    {
        printf("too many arguments  exit for minishell\n");
        data->error = 2;
    }
    oll_free(data);
    exit(data->error);
}