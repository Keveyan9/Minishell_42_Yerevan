#include "minishell.h"

void logic(t_src *data)
{

    if (chek_coll_builtin(data) == 0);
    else
        coll_comands(data);
}
