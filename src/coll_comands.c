#include "minishell.h"

static char **list_to_array(t_src *data)
{
    char **env_aray;
    int row;
    int calem;
    t_env *origin;
    char *key_equal;
    int i;

    i = 0;
    origin = data->env;
    row = 0;
    calem = 0;
    while (origin)
    {
        origin = origin->next;
        row++;
    }
    env_aray = (char **)malloc(sizeof(char *) * (row + 1));
    if (!env_aray)
        return (NULL);
    origin = data->env;
    while (origin)
    {
        key_equal = ft_strjoin(origin->key, "=");
        env_aray[i++] = ft_strjoin(key_equal, origin->value);
        free(key_equal);
        origin = origin->next;
    }
    env_aray[i] = NULL;
    return (env_aray);
}

void coll_comands(t_src *data)
{
    char *comand_path;
    char **env;

    comand_path = find_comand_path(data);
    env = list_to_array(data);
    data->error = execve(comand_path, data->cl_in->word, env);
    frik(env);
    free(comand_path);
    if (data->error != 0)
        perror("execve");
    /// stex karoxa petq e exit avelcanel vor ete execve chashxati free ani durs ga
    // bayc ed en depqum erb inqe chayldi mej e
}
