/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:50:44 by artadevo          #+#    #+#             */
/*   Updated: 2023/01/22 20:12:31 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int main(int ac, char **av, char **env)
{
	t_src *data;
///__clen input///
    t_cl_in *in;
    (void)ac;
    (void)av;
    data = malloc(sizeof(t_src));
    if (!data)
        return (0);
    start_input(data, env);


    ///test after need clinig //
    in =  malloc(sizeof(t_cl_in));
  
    data->cl_in = in;
    data->cl_in->id = ft_strdup("ls");
    data->cl_in->word = ft_split("ls -l" ,' ');
    chek_coll_builtin(data);
    char *comand_path = find_comand_path(data,data->cl_in->id);
    char *s = " ls -la";
   //printf("test_%s\n", comand_path);
    //execve(comand_path,data->cl_in->word,env);
    if(access("/home/go/Desktop/Minishell/src",F_OK))
        printf("sxal\n");
    char *args[] = {"/Desktop/Minishell/src", "test.ou"};
    char *envp[] = {NULL};


    if (execve(args[0], args, env) == -1) {
        perror("execve");
        exit(EXIT_FAILURE);
    }
  //chek_coll_builtin(data);
 
    return (0);
}


//int main(int ac, char **av, char **env)
// {
//     char *args[] = {"/bin/ls", "-la", "/tmp", NULL};
//     char *envp[] = {NULL};

//     // if (execve(args[0], args, env) == -1) {
//     //     perror("execve");
//     //     exit(EXIT_FAILURE);
//     // }
//     printf("gago tes\n");

//     return 0;
// }