/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:50:44 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/05 20:06:09 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	t_src	*data;
	// t_cl_in	*in;
	// pid_t	pid;
	(void)ac;
	(void)av;
	data = malloc(sizeof(t_src));
	if (!data)
		return (0);
	data = all_input(data, env);
	while (1)
	{
		data = start_input(data);
		ft_read_l(data);
		data = syntax_error(data);
		if (data->pipes_count == 0)
		{
			if (chek_coll_builtin(data) == 1)
				alone_child(data);
		}
		else
			realaysing(data);
		oll_free(data);
	}
	return (0);
}	
// clin(data);
	// ////	// coll_comands(data);
