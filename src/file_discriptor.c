#include "minishell.h"

static void chek_in_file(t_src *data, int *row)
     {
        char *name;
        int len;

        len = *row;
        if(data->cl_in->in_fd > 0)
            close(data->cl_in->in_fd);
        while(data->cl_in->oll[len]!= ' ' && data->cl_in->oll[len])
            len++;
        name = ft_substr(data->cl_in->oll,*row,len);
        data->cl_in->out_fd = open (name, O_RDONLY, 0644);
        if(data->cl_in->out_fd == -1)
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
    //printf("##__%s__\n",&(data->cl_in->oll[*row]));
    if(data->cl_in->oll[*row] == '>')
     {  
        printf("__%s__\n",&(data->cl_in->oll[*row]));
        // if(data->cl_in->oll[*row]== ' ')
        //     (*row)++;
        // len = *row;
        // while(data->cl_in->oll[len]!= ' ')
        //     len++;
        // name = ft_substr(data->cl_in->oll,*row,len);
        //  printf("__%s__\n",name);
        // data->cl_in->out_fd = open (name, O_RDWR | O_CREAT | O_APPEND, 0644);
    }
    else
    {    
        len = *row;
        while(data->cl_in->oll[len]!= ' ' && data->cl_in->oll[len])
            len++;
        name = ft_substr(data->cl_in->oll,*row,len);
        data->cl_in->out_fd = open (name, O_RDWR | O_CREAT | O_TRUNC, 0644);
        data->error = errno;
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
            row++;
            if(data->cl_in->oll[row] == ' ')
                row++;
            chek_in_file(data,&row);
         }
        row++;
    }
}