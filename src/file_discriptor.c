#include "minishell.h"
int find_plase(char *s , char c)
{
    int n;

    n = 0;
    if(!s)
        return(0);
    while(s[n] && s[n] != c)
        n++;
    if(s[n] == c);
    else
        n++;
    return(n);
}

static void chek_in_file(t_src *data, int *row)
     {
        char *name;
        int len;

        len = *row;
        if(data->cl_in->out_fd > 0)
            close(data->cl_in->out_fd);
        len   = find_plase(&(data->cl_in->oll[*row]),' ');
        name = ft_substr(data->cl_in->oll,*row,len);
        data->cl_in->in_fd = open (name, O_RDONLY, 0644);
        (*row) = (*row) + len - 1;
        if(data->cl_in->in_fd == -1)
        {
            ft_putstr_fd(name,1);
            ft_putstr_fd(" : No such file or directory\n",1);
            data->error = 1;
        }
        free(name);
        name = NULL;
     }

static void chek_out_file(t_src *data, int *row)
{
  char *name;
    int len;

    if(data->cl_in->out_fd > 0)
        close(data->cl_in->out_fd);
    if(data->cl_in->oll[*row] == '>')
     { 
        (*row)++;
        if(data->cl_in->oll[*row]== ' ')
            (*row)++;
        len = find_plase(&(data->cl_in->oll[*row]),' ');
        name = ft_substr(data->cl_in->oll,*row,len );
        data->cl_in->out_fd = open (name, O_RDWR | O_CREAT | O_APPEND, 0644);
        (*row) = (*row) + len;
    }
    else
    { 
        len = find_plase(&(data->cl_in->oll[*row]),' ');
        name = ft_substr(data->cl_in->oll,*row,len );
        data->cl_in->out_fd = open (name, O_RDWR | O_CREAT | O_TRUNC, 0644);
        data->error = errno;
         (*row) = (*row) + len ;
    }
    free(name);
    name = NULL;
}


void file_discriptor(t_src * data)
{
    int row;

    row = 0;
    while (data->cl_in->oll[row])
    {
        if(data->cl_in->oll[row] == '>')
        {
            row++;
            if(data->cl_in->oll[row] == ' ')
                row++;
           chek_out_file(data,&row);
        }     
        else if (data->cl_in->oll[row] == '<' && (data->cl_in->oll[row + 1] != '<')) 
        { 
            if(  row == 0 || ( row > 0 && (data->cl_in->oll[row - 1] != '<' ) ))
            {
                row++;
                if(data->cl_in->oll[row] == ' ')
                    row++;
                 chek_in_file(data,&row);
            }
         }
        row++;
    }
}