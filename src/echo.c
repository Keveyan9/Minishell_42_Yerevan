#include "minishell.h"

void echo(char **s)
{
    int calem;
    int row;
    int flag;
    calem = 1;
    flag = 1;
    if (s[1][0] == '-' && s[1][1] =='n')
        {
            while(s[1][++calem] == 'n');
            if(ft_strlen(s[1]) == calem)
             {
               calem = 2;
                flag = 0;
             }
            else
                calem = 1;
        }
    else
        calem = 1;
    while(s[calem])
    {
        while(s[calem][row])
            write(1,&s[calem][row++],1);
        write(1," ",1);
        row = 0;
        calem++;
    }
    if (flag)
        write(1,"\n",1);
}
