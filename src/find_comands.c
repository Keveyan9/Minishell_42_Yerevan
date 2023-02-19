#include"minishell.h"

char *find_comand_path(t_src *data, char *s)
{
    char **oll_path;
    char *comand_slesh;
    char *path_chek;
    t_env *env_list;
    int n;

    path_chek = NULL;
    n = 0;
    env_list = find_env(data->env,"PATH");
    if(!env_list)
        {
            printf("%s: No such file or directory \n",s);
            return(NULL);
        }
    comand_slesh = ft_strjoin("/",s);
    oll_path = ft_split(env_list->value,':');
    while (oll_path[n])
    {
        if(path_chek)
            free(path_chek);
        path_chek = ft_strjoin(oll_path[n++],comand_slesh);
        if(!access(path_chek, F_OK))
        {
            free(comand_slesh);
            frik(oll_path);
            return(path_chek);
        }
    }
   free (comand_slesh);
   frik(oll_path);
    if(path_chek)
        free(path_chek);
    return(NULL);
}

// char  **chekin_comands ( int argc,char **argv, char **env,int *path_chek_i)
// {
// char **comands_path;
	
// 	var.path_i = 0;
// 	var.comands_n = 0;
// 	var.path = faund_path(env);

// 	comands_path = (char **) malloc(sizeof(char**)*(argc - 3)*4 + 1);
// 	if(!var.comands_path)
// 		exit(0);
// 	while(var.comands_n < argc - 3)
//  	{	
// 		var.comands = ft_split(argv[var.comands_n + 2],' ');
// 	while(var.path[var.path_i] && (access(( var.path_chek = 
// 							ft_strjoin(var.path[var.path_i],(var.comand_slesh = ft_strjoin("/",var.comands[0])))),F_OK)))
// 				{
// 					free(var.path_chek);	
// 					free(var.comand_slesh);
// 					var.path_i++;
// 				}
// 		if(var.path[var.path_i] && !access(var.path_chek,F_OK ))
// 			{
// 				var.comands_path[(*path_chek_i)++] = var.path_chek;
// 				free(var.comand_slesh);
// 			   	var.comands_path[(*path_chek_i)++] = var.comands[0];
// 				var.comands_path[(*path_chek_i)++] = var.comands[1];
// 				var.comands_path[(*path_chek_i)++] = NULL;
// 				var.path_i = 0;	
// 			}
//     	else
// 		{
// 			if(var.path_chek)
// 				free(var.path_chek);
// 			if(var.comand_slesh)
// 				free(var.comand_slesh);
// 			write(1,"not found comand",20);
// 			exit(0);
// 		}
// 		var.comands_n++;
// 		free(var.comands);
// 	}
// 		var.comands_path[(*path_chek_i)++] = NULL;
// 	frik(var.path);
// 	return(var.comands_path);
// }
