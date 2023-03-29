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

static void cheak_old_fd(t_src *data, int *fd, int *n)
{
    printf("_chek1_%s__\n",&(data->cl_in->oll[*n]));
    while(data->cl_in->oll[*n] && data->cl_in->oll[*n] != '<' )
        (*n)++;
    if(data->cl_in->oll[*n] == '\0')
    {
        printf("last fd\n");
        if(data->cl_in->pip_her_doc[0] > 0)
            close(data->cl_in->pip_her_doc[0]);
        data->cl_in->pip_her_doc[0] = *fd;       
    }
    else
        close(*fd);
}

static void chek_in_file(t_src *data, int *row)
     {
        char *name;
        int len;
        int fd;
        int n;

        fd = 0;
        len = *row;
        n = *row;
        if(data->cl_in->out_fd > 0)
            close(data->cl_in->out_fd);
        len   = find_plase(&(data->cl_in->oll[*row]),' ');
        name = ft_substr(data->cl_in->oll,*row,len);
        fd = open (name, O_RDONLY, 0644);
        (*row) = (*row) + len - 1;
        if(fd == -1)
        {
            ft_putstr_fd(name,1);
            ft_putstr_fd(" : No such file or directory\n",1);
            data->error = 1;
            g_flags = 1;
            return;
        }
        cheak_old_fd(data, &fd, &n);
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
        data->cl_in->pip_her_doc[1] = open (name, O_RDWR | O_CREAT | O_APPEND, 0644);
        data->error = errno;
        (*row) = (*row) + len;
    }
    else
    { 
        len = find_plase(&(data->cl_in->oll[*row]),' ');
        name = ft_substr(data->cl_in->oll,*row,len );
        data->cl_in->pip_her_doc[1] = open (name, O_RDWR | O_CREAT | O_TRUNC, 0644);
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
    while ( data->cl_in->oll[row] && !g_flags)
    {
        if(data->cl_in->oll[row] == '>')
        {
            data->error = 0;
            row++;
            if(data->cl_in->oll[row] == ' ')
                row++;
           chek_out_file(data,&row);
           if(data->error != 0)
                g_flags = 1;
        }     
        else if (data->cl_in->oll[row] == '<' && (data->cl_in->oll[row + 1] != '<')) 
        { 
            data->error = 0;
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