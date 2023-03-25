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

void child_coneqt(t_src *data)
{ 
	//signali funkcian stex grem
	
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
}
