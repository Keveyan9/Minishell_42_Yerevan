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
	//printf("%d", data->pipes_count);
	data->ciqel = 0;
	data->pip = malloc(sizeof(*(data->pip)) * data->pipes_count);
	if (!data->pip)
	{
		write(1, "can not duing malloc\n", 21);
		return ;
	}

	while (data->pid  && data->pipes_count >= data->ciqel)
	{
		 if(data->pipes_count > data->ciqel)
			pipe(data->pip[data->ciqel]);
		data->pid = fork();
		if (data->pid < 0)
		{
			write(1, "can not creat child\n", 20);
			break ;
		}
		if (data->pid > 0)
		{
			data->cl_in = data->cl_in->next;
			data->ciqel++;
		}
	}
	if (data->pid == 0)
		child(data);
	if (data->pid > 0)
	{
		close_discriptor(data);
		 while(data->pipes_count--)
		 {
			data->error = 0;
		 	wait(&data->error);
		 }
		 free(data->pip);
	}
}
