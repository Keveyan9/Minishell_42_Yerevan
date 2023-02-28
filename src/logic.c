#include "minishell.h"

void logic(t_src *data)
{
    // stex eli baner ka anelu asenq papka bacel pakel es shat gidem dolar molar vercnele
    // stex en masna vor arancin mi procesi mej piti katarvi
  ///  ft_printf("%s_%s\n",data->cl_in->id,data->cl_in->oll);
   //exit;
    if (chek_coll_builtin(data) == 0);
    else
        coll_comands(data);
    exit;
   // oll_free(data);    
}
