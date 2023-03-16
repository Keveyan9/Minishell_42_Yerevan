/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realaysing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:45:50 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 16:46:14 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	realaysing(t_src *data)
{
	pid_t	pid;

	pid = 0;
	write(1,"realayzi\n",9);
	data->ciqel = 0;
	data->pip = malloc(sizeof(*(data->pip)) * data->pipes_count);
	if (!data->pip)
	{
		write(1, "can not duing malloc\n", 21);
		return ;
	}
	data->pipes_count++;
	while (pid == 0 && data->pipes_count)
	{
		if (data->pipes_count-- > 1)
			pipe(data->pip[data->ciqel]);
		pid = fork();
		if (pid < 0)
		{
			write(1, "can not creat child\n", 20);
			break ;
		}
		if (pid == 0)
		{
			data->cl_in = data->cl_in->next;
			data->ferst_child++;
			if (data->pipes_count > 1)
				data->ciqel++;
		}
	}
	if (pid > 0)
		child(data);
	if (pid == 0)
	{
		free(data->pip);
	}
}
