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

static void test(t_src *data)
{
	write(1, "test\n", 5);
	oll_free(data);
	exit;
}

void close_discriptor(t_src *data, int d ,int ds)
{
	int n;

	n = 0;
	write(ds, "@@@", 3);
	ft_putnbr_fd(d,ds);
	write(ds, "\n", 1);
	write(ds, "#", 1);
	ft_putnbr_fd(data->pip_doing,ds);
	write(ds, "#", 1);
	write(ds, "\n", 1);
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
		close_discriptor(data, data->cycle,2);
		logic(data);
		//test(data);
	}
	else if (data->cycle > 0 && !(data->cycle == data->pipes_count) && data->error == 0)
	{
		// printf("%s__%d__%d\n",data->cl_in->id, data->pipes_count, data->cycle);
		// printf("2__%s__%d__%d\n",data->cl_in->id, data->pipes_count, data->cycle);
		dup2(data->pip[data->cycle - 1][0], 0);
		dup2(data->pip[data->cycle][1], 1);
		close_discriptor(data, data->cycle,2);
		logic(data);
		//test(data);
	}
	else if (data->cycle == data->pipes_count || data->error != 0)
	{

		dup2(data->pip[data->cycle - 1][0], 0);
		close_discriptor(data, data->cycle,1);
		logic(data);
		//test(data);
	}
	exit(data->error);
}
