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

void	ft_read_l(t_src *data)
{
	free (data->line);
	data->line = readline("mini$ ");
	if (data->line)
		add_history(data->line);
	// //data = ft_parser(data);
//	data->line = readline("mini$ ");
	// //data = ft_parser(data);
	// 	printf("[%s]\n", data->line);
	// return ;
}
