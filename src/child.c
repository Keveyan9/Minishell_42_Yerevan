/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:07:57 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/02 17:08:03 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	child_coneqt(t_src *data)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	if (data->cycle == 0)
	{
		dup2(data->pip[data->cycle][1], 1);
		logic(data);
	}
	else if (data->cycle > 0 && !(data->cycle == data->pipes_count)
		&& data->error == 0)
	{
		dup2(data->pip[data->cycle - 1][0], 0);
		dup2(data->pip[data->cycle][1], 1);
		logic(data);
	}
	else if (data->cycle == data->pipes_count)
	{
		dup2(data->pip[data->cycle - 1][0], 0);
		logic(data);
	}
}