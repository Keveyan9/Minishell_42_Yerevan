#include "minishell.h"

void env_fri(t_env *fri_segment)
{
    free(fri_segment->key);
    free(fri_segment->value);
    free(fri_segment);
}
