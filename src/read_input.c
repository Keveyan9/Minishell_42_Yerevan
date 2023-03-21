/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:17:47 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/05 20:05:22 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void ft_read_l(t_src *data)
{
	while (!(data->line) ||  data->line[0] == '\0')
	{
		data->line = readline("mini$ ");
		if(data->line[0] != '\0')
			add_history(data->line);
		if(data->line[0] == '\0')
		{
			data->error = 130 ;
			free(data->line);
			data->line = NULL;
			start_input(data);
		}
	}
	// data->cl_in = malloc (sizeof(t_cl_in)*1);
	// data->cl_in->oll = data->line;
	// data->cl_in->word = ft_split(data->line, ' ');
	// data->cl_in->id = ft_strdup("gago");
	// data->cl_in->next = NULL;
	// data->cl_in->prev = NULL;
	// //data = ft_parser(data);
	//	data->line = readline("mini$ ");
	// //data = ft_parser(data);
	// 	printf("[%s]\n", data->line);
	// return ;
}
