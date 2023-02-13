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
    data->cl_in->id = ft_strdup("echo");
 //env_f(data);
    data->cl_in->word = ft_split("cd ../../Tumo",' ');
    data->cl_in->oll = ft_strdup("echo -n gaeg wafer df e r mnlm");
   //cd(data);
   // pwd();
    //free(data->cl_in->word);
    data->cl_in->word = ft_split("unset OLDPWD",' ');
   // env_f(data);
    unset(data);
   // env_f(data);	
    data->cl_in->word = ft_split("export  test+=154  fefes",' ');
   echo(data);
 //   cd(data);
   // env_f(data);
   printf("%d");
    export(data);
    return (0);
}
