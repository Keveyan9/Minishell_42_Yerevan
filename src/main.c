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
	t_src *data;

	(void)ac;
	
	data = malloc(sizeof(t_src));
	if (!data)
		return (0);
	if (all_input(data, env))
		return (0);
	shell_level(data,av);
	while (1 && data->pid > 0)
	{
		start_input(data);
		ft_read_l(data);
		data = syntax_error(data);
			while (data->cl_in->prev)
				data->cl_in = data->cl_in->prev;
			data->clin_head = data->cl_in;
		printf("__%d__\n",data->pipes_count);
		
		if (data->line)
		{
			free(data->line);
			data->line = NULL;
		}
		if (data->pipes_count == 0)
			alone(data);
		else
			realaysing(data);
			//stex karoxa petq cl_In hedov maqrel vor amen angam whilov chfra
		data->cl_in = data->clin_head;
		if (data->cl_in)
			free_clin(data);
		free(data->line);
		data->line = NULL;
	}
		oll_free(data);
	return (0);
}