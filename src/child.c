/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:02:42 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 16:02:47 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static void	close_discriptor(t_src *data)
{
	int	n;

	n = 0;
	while (n <= data->ciqel)
	{
		close(data->pip[n][0]);
		close(data->pip[n++][1]);
	}
}

void	child(t_src *data)
{
	if (data->ferst_child == 0 && data->pipes_count > 0)
	{
		dup2(data->pip[data->ciqel][1], 1);
		close_discriptor(data);
		logic(data);
	}
	else if (data->ferst_child > 0 && data->pipes_count == 0)
	{
		dup2(data->pip[data->ciqel][0], 0);
		close_discriptor(data);
		logic(data);
	}
	else
	{
		dup2(data->pip[data->ciqel - 1][0], 0);
		dup2(data->pip[data->ciqel][1], 1);
		close_discriptor(data);
		logic(data);
	}
}
