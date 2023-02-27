#include "minishell.h"

void alone_child(t_src *data)
{
    pid_t pid;

    pid = 0;
    pid = fork();
    if (pid < 0)
        write(1, "can not creat child\n", 20);
    else if (pid > 0)
    {
        coll_comands(data);
        // this momenta need chek in liaks in this porces ;
        oll_free(data);
        exit;
    }
}
