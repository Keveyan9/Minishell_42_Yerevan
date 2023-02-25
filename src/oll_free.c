#include "minishell.h"

void oll_free(t_src *data)
{
    free_clin(data);
    free_env(data);
    free(data);
}
