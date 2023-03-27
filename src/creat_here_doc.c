#include "minishell.h"

static int coll_hear_doc(t_src *data, int *row)
{
    int fd[2];
    int len;
    char *her_line;
    char *close_name;
    (*row)++;
    len = 0;
    len = find_plase(&(data->cl_in->oll[*row ]),' ');
    close_name = ft_substr(data->cl_in->oll,*row,len );
    pipe(fd);
    her_line = NULL;
    while (1)
    {
        her_line = readline(">");
        if (her_line == NULL)
        {
            data->error = 1;
            return(1);
        }
        if(ft_strncmp(her_line,close_name,ft_strlen(close_name)) == 0)
            break;
        write(fd[1],her_line,ft_strlen(her_line));
        write(fd[1],"\n",1);
    }
    close(fd[1]);
    if(data->cl_in->in_fd > 0)
        close(data->cl_in->in_fd);
    data->cl_in->in_fd = fd[0];
    free(close_name);
    close_name = NULL;  
    return(0);
}

int creat_here_doc(t_src *data)
{
    int row;

    row = 0;
    while (data->cl_in != NULL )
    {   
        while(data->cl_in->oll[row] != '\0' )
        {
            if(data->cl_in->oll[row] == '<' && data->cl_in->oll[ ++ row] == '<')
            {
                 if( data->cl_in->oll[row] == ' ')
                    row++;
               if(coll_hear_doc(data,&row))
                    return(1);
            }
            row++;
        }
        row = 0;
        data->cl_in = data->cl_in->next;
    }
    data->cl_in = data->clin_head;
    return(0);
}