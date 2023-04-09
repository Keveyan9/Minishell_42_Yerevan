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
	size_t	n;

	while (!(data->line) || data->line[0] == '\0')
	{
		n = 0;
		data->line = readline("mini$  ");
		if (data->line == NULL)
		{
			oll_free(data);
			exit(data->error);
		}
		if (data->line[0] != '\0')
			add_history(data->line);
		if (data->line[0] == '\0')
			free_give_null(&data->line);
		while (data->line && data->line[n] == 32)
			n++;
		if (ft_strlen(data->line) == n)
			free_give_null(&data->line);
	}
}
