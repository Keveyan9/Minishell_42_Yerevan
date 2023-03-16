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
	data->line = readline("mini$ ");
		add_history(data->line);
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
