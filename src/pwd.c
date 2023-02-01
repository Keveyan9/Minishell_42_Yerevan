#include "minishell.h"

void pwd()
{
    char *v_pwd;

    v_pwd = getcwd(NULL,0);
    printf("%s\n",v_pwd);
    free(v_pwd);
}
