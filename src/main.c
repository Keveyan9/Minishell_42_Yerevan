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
	t_cl_in *in;
	pid_t pid;
	(void)ac;
	(void)av;
	int flag = 1;
	data = malloc(sizeof(t_src));
	pid = 0;
	if (!data)
		return (0);

    start_input(data, env);
    //printf("test\n");
	data->ferst_child = 0;
	data->pipes_count = 2;
	clin(data);
	////	// coll_comands(data);
	if (data->pipes_count == 0)
	{
		if (chek_coll_builtin(data) == 1)
			alone_child(data);
	}
	else
		realaysing(data);
	 oll_free(data);
    printf("test\n");
	return (0);
	//	mnac piperi pahe dzem haskanam inch e linum
}
