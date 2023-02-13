#include "minishell.h"

static void call_$(char *s,t_src *data ,int n)
{
    n++;
    while(s[n] && !(s[n] > 20 && s[n] < 65))
        n++;
        while(s[n])
        {
        if( s[n-1] == '$' && s[n] == '?')
        {
            ft_printf("%d",data->error);
               n = n+2;
        }
        else
        {
            write(1,&s[n],1);
            n++;
        }
        }
}

void echo(t_src *data)
{
    int calem;
    int row;
    int flag;
    calem = 1;
    flag = 1;
    row = 0;
    if (data->cl_in->word[1][0] == '-' && data->cl_in->word[1][1] =='n')
        {
            while(data->cl_in->word[1][++calem] == 'n');
            if(ft_strlen(data->cl_in->word[1]) == calem)
             {
               calem = 2;
                 flag = 0;
             }
            else
                calem = 1;
        }
    else
        calem = 1;
 while(data->cl_in->word[calem])
 {
    while(data->cl_in->word[calem][row])
    {
        if( data->cl_in->word[calem][row] == '$')
        {
            call_$(data->cl_in->word[calem], data,row);
            break;
        }
        else
            write(1,&(data->cl_in->word[calem][row++]),1);
    }
    if((data->cl_in->word[calem + 1 ] )&& ((calem >= 2 && flag == 0) || (calem >= 1 && flag == 1)))
           write(1," ",1);
    row = 0;
    calem++;
    if (flag)
        write(1,"\n",1);
}
}