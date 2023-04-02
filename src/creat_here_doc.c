#include "minishell.h"

int g_flags;

static void handler(int sig)
{
    (void)sig;
    g_flags = 1;
    ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_replace_line("", 0);
	rl_on_new_line();
}

static void chek_dolar_push(t_src *data, char *her_line,int flag_doing_dolar)
{
    char **her_line_s;
    int n;

    n = 0;
    her_line_s = NULL;
    if(!flag_doing_dolar)
    {
        her_line_s = ft_split(her_line,' ');
        while(her_line_s[n])
        {
            if(her_line_s[n][0] == '$')
                dolar_change(data->env,&(her_line_s[n]),1);
            write(data->cl_in->pip_her_doc[1],her_line_s[n],ft_strlen(her_line_s[n]));
            n++;
        }
        frik(her_line_s);
    }
    else
        write(data->cl_in->pip_her_doc[1],her_line,ft_strlen(her_line));
    write(data->cl_in->pip_her_doc[1],"\n",1);

}

static void readline_heredoc(t_src *data,char *close_name)
{
    char *her_line;
    int flag_doing_dolar;
    
    g_flags = 0;
    flag_doing_dolar = 0;
     if(close_name[1] && close_name[1] != 39)
        flag_doing_dolar = 1;
    signal(SIGINT, handler);
    while(!g_flags)
    {
        her_line = readline(">");   
        if (her_line == NULL)
        {
            data->error = 1;
            break;
        }
        if(ft_strncmp(her_line, &(close_name[flag_doing_dolar]), ft_strlen(close_name) + ft_strlen(her_line)) == 0)
        {
            free(her_line);
            break;
        }
        chek_dolar_push(data, her_line,flag_doing_dolar);
        free(her_line);
        her_line = NULL;
    }
}

static int coll_hear_doc(t_src *data, int *row)
{
    int len;
    char *close_name;

    (*row)++;
    len = 0;
    len = find_plase(&(data->cl_in->oll[*row]),' ');
    close_name = ft_substr(data->cl_in->oll,*row,len);
    if(data->cl_in->pip_her_doc[0] > 0 )
        close(data->cl_in->pip_her_doc[0]);
    pipe(data->cl_in->pip_her_doc);
    readline_heredoc(data,close_name);
    if(g_flags)
        data->error = 130;
    close(data->cl_in->pip_her_doc[1]);
    data->cl_in->pip_her_doc[1] = 0;
    free(close_name);
    close_name = NULL;  
    signal(SIGINT, SIG_IGN);
    return(0);
}

int creat_here_doc(t_src *data)
{
    int row;

    row = 0;
    while (data->cl_in != NULL  ) 
    {   
        while(data->cl_in->oll[row] != '\0')
        {
            if(data->cl_in->oll[row] == '<' && data->cl_in->oll[ ++ row] == '<')
            {
                data->error = 0;
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