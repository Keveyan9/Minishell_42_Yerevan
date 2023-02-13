#include "minishell.h"

int find_index(char *s,char c)
{
    int i;

    i = 0;
    while(s[i])
        if(s[i++] == c)
            return(i);
    return(0);
}

static int chek_key(char *s)
{
    int n;

    n = 0;
    if(ft_isalpha(s[0]))
         while(ft_isalnum(s[n++]));
    if(n == ft_strlen(s))
        return(0);
    printf(": %s : not a valid identifier\n",s);
    return(1);
}

static int clin_creat(char **s, int lenqt)
{
    if(*s)
        free(*s);
    *s = (char* ) malloc(sizeof(lenqt));
    if(!s)
        return(1);
    return(0);
}

void export (t_src *data)
{
    t_export var;

    var.value = NULL;
    var.key = NULL;
    var.add = 0;
    var.row = 1;
    
    if(data->cl_in->word[1])
    {
        while (data->cl_in->word[var.row])
        {
            if (!ft_isalpha(data->cl_in->word[var.row][0]))
                {
                   ft_printf("is not valid argument %s\n", data->cl_in->word[var.row]);
                    break;
                }
             var.i = find_index(data->cl_in->word[var.row],'=');
             var.string_len = ft_strlen(data->cl_in->word[var.row]);
            if(var.i)
             {
                if(data->cl_in->word[var.row][var.i-2] == '+')
                    var.add = 1;
            clin_creat(&(var.key),(var.i + 1 - var.add));
            ft_strlcpy(var.key,data->cl_in->word[var.row], var.i - var.add);
            clin_creat(&(var.value),(var.string_len - var.i));
            ft_strlcpy(var.value,&(data->cl_in->word[var.row][var.i]),var.string_len - var.i + 1);
            printf("%d ___ %s __%s\n",var.i,var.key,var.value);

            // var.find_key = find_env(data->env,var.key);
            // if (var.find_key)
            // {   
            //   if(var.add)
            //        var.addstring = ft_strjoin(var.find_key->value,var.value);       
            //         free(var.find_key->value);
            //         var. find_key->value = var.addstring;
            //     }
            //     else
            //     {
            //       free(var.find_key->value);
            //      var.find_key->value = var.value;
            //     }
          //  }
          //  else
             // printf("now nod \n");
           }
             else
            {
                printf("chek key and creat now node only key");
            }
           var.row++; 
        }
    }
    else
        ft_printf("prinf est aji\n");
}