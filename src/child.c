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

 void	close_discriptor(t_src *data)
{
	int	n;

	n = 0;
	while (n < data->pipes_count)
	{
		close(data->pip[n][0]);
		close(data->pip[n++][1]);
	}
}

void	child(t_src *data)
{
	//printf("%s__%d__%d\n",data->cl_in->id, data->pipes_count, data->ciqel);
	if (data->ciqel == 0 )
	{
		//printf("1__%s__%d__%d\n",data->cl_in->id, data->pipes_count, data->ciqel);
		dup2(data->pip[data->ciqel][1], 1);
		close_discriptor(data);
		logic(data);
	}
	else if (data->ciqel > 0 && !(data->ciqel == data->pipes_count))
	{
		//printf("2__%s__%d__%d\n",data->cl_in->id, data->pipes_count, data->ciqel);
		dup2(data->pip[data->ciqel - 1][0], 0);
		dup2(data->pip[data->ciqel][1], 1);
		close_discriptor(data);
		logic(data);
	}
	else if ( data->ciqel == data->pipes_count)
	{
		dup2(data->pip[data->ciqel-1][0], 0);
		close_discriptor(data);
			logic(data);
	}
}
