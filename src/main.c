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
     data->cl_in->word = ft_split("ls -la" ,' ');
  // chek_coll_builtin(data);
  //  export(data);
   //  env_f(data);

    //heto grel fork pahere 
   coll_comands(data); 
     free(data->cl_in->id);
     frik(data->cl_in->word);
     free(in);
    free_env(data);
    free(data);
   // while (1);
      return (0);
}