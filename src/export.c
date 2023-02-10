#include "minishell.h"

int find_index(char *s,char c)
{
    int i;

    i = 0;
    while(s[i])
    {
        if(s[i++] == c)
            return(i);
    }
    return(0);
}

static int chek_key(char *s)
{
    int n;

    n = 0;
    if(ft_isalpha(s[0]))
    {
         while(ft_isalnum(s[n++]));
    }
    if(n == ft_strlen(s))
        return(0);
    printf(": %s : not a valid identifier\n",s);
    return(1);
}

void export (t_src *data)
{
    t_export var;

    var.value
     = NULL;
    var.key = NULL;
    var.add = 0;
    var.row = 1;
    
    if(data->cl_in->word[1])
    {
        while (data->cl_in->word[var.row])
        {
             var.i = find_index(data->cl_in->word[var.row],'=');
             var.string_len = ft_strlen(data->cl_in->word[var.row]);
        if(var.i)
        {
            if(data->cl_in->word[var.row][var.i-2] == '+')
                var.add = 1;
            if(var.key)
                free(var.key);
            if (var.value
            )
                free(var.value
                );
            var. key = (char* ) malloc(var.i + 1 - var.add);
            if(!var.key)
                return;
            var.value
             = (char*) malloc (var.string_len - var.i);
            if(!var.value
             )
                return;
            ft_strlcpy(var.key,data->cl_in->word[var.row], var.i - var.add);
            ft_strlcpy(var.value
            ,&data->cl_in->word[var.row][var.i],var.string_len - var.i + 1);
            var.find_key = find_env(data->env,var.key);
        //printf("%s___%s\n",var.key,var.value
        

            if (var.find_key)
            {   
              if(var.add)
                {
                   var.addstring = ft_strjoin(var.find_key->value,var.value
                   );       
                    free(var.find_key->value);
                    var. find_key->value = var.addstring;
                
                }
                else
                {
                  free(var.find_key->value
                  );
                 var.find_key->value = var.value;
                }
            }
            else
                printf("%s\n",data->cl_in->word[var.row]);
        var.row++;
       
    }
            else;
 
                //now node
        }
 
    }
}
