#include "minishell.h"

void alone(t_src *data)
{
    //stex piti phail diskriptor baci paki bayc et en depqum erb biltin e ete voch childi mej piti ani
    if(chek_coll_builtin(data) == 0 );
    else
        alone_child(data);
}