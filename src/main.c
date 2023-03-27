/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:50:44 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/27 01:39:02 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

// static void handler(int sig)
// {
// 	if (sig == SIGINT)
// 		write(1,"\n",1);
// 	exit(1);
// }
//pwd | >a <<h << es stex mtacel em vor koxqe hastat anun ka ete anun chka piti ta anexpedit token ta u 
//pwd | wc -l >b |  >a <<h >>  orinak es paragayum el b piti chstexci

int main(int ac, char **av, char **env)
{
	t_src *data;
	//char *s;

	(void)ac;

	data = malloc(sizeof(t_src));
	if (!data)
		return (0);
	if (all_input(data, env))
		return (0);
	shell_level(data, av);
	while (1 && data->pid > 0)
	{
		
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		start_input(data);
		ft_read_l(data);
		data = syntax_error(data);
		if(creat_here_doc(data) == 0 && data->syntax_err)
		{
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
		}
		if (data->syntax_err != 0)
			print_syntax_err(data); // grel exit funkcia
	}
	oll_free(data);
	return (0);
}