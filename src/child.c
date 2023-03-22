/* **************************safsa************************************************ */
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

void close_discriptor(t_src *data)
{
	int n;

	n = 0;
	while (n < data->pip_doing)
	{
		close(data->pip[n][0]);
		close(data->pip[n][1]);
		n++;
	}
}

void child_coneqt(t_src *data)
{
	if (data->cycle == 0)
	{
		dup2(data->pip[data->cycle][1], 1);
		close_discriptor(data);
		logic(data);
	}
	else if (data->cycle > 0 && !(data->cycle == data->pipes_count) && data->error == 0)
	{
		dup2(data->pip[data->cycle - 1][0], 0);
		dup2(data->pip[data->cycle][1], 1);
		close_discriptor(data);
		logic(data);
	}
	else if (data->cycle == data->pipes_count )
	{
		dup2(data->pip[data->cycle - 1][0], 0);
		close_discriptor(data);
		logic(data);
	}
	oll_free(data);
	exit(data->error);
}
