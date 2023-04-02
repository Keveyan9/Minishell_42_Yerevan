/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alone_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:49:38 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 15:49:46 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	alone_child(t_src *data)
{
	int		d;

	data->pid = 0;
	data->pid = fork();
	d = 0;
	if (data->pid < 0)
	{
		write(1, "can not creat child\n", 20);
		data->error = errno;
	}
	else if (data->pid == 0)
	{	
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_IGN);
		file_discriptor(data);
		if (!g_flags)
		{
			change_fd(data);
			close_herdoq_fd(data);
			coll_comands(data);
		}
		oll_free(data);
		exit(data->error);
	}
	else if (data->pid > 0)
	{
		wait(&d);
		data->error = WEXITSTATUS(d);
		return (0);
	}
	return (0);
}
