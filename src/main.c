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

// static void handler(int sig)
// {
// 	if (sig == SIGINT)
// 	{
//  		write(1, "test\n", 5);
// 	}
// 	//exit(1);
// }

int main(int ac, char **av, char **env)
{
	t_src *data;
	int flag;

	flag = 1;
	(void)ac;
	
	data = malloc(sizeof(t_src));
	if (!data)
		return (0);
	if (all_input(data, env))
		return (0);
	shell_level(data,av);
	while (1 && data->pid > 0)
	{
		//signal(SIGINT, handler);
		if(flag == 1)
			data->error = 0;
		else
			data->error = 1;
		flag = 0;
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
		data->cl_in = data->clin_head;
		if (data->cl_in)
			free_clin(data);
		free(data->line);
		data->line = NULL;
		flag = 1;
	}
		oll_free(data);
	return (0);
}