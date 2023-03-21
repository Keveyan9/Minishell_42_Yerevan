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


void create_child(t_src *data)
{
	int pip_eror ;
	while ( data->pid > 0 && data->pipes_count >= data->cycle)
	{
		if (data->pipes_count > data->cycle)
		{
			pip_eror = pipe(data->pip[data->cycle]);
			if (pip_eror != 0)
			{
				ft_putnbr_fd(data->pip_doing,2);
				perror("pip");
				data->error = pip_eror;
				break;
			}
			data->pip_doing++;
		}
		data->pid = fork();
		if (data->pid > 0 )
		{
			data->cl_in = data->cl_in->next;
			data->cycle++;
		}
		if (data->pid < 0)
		{
			perror(" child problems ");
			data->error = data->pid;
			break;
		}
	}
}

void realaysing(t_src *data)
{
	//printf("_______________________%d______________\n", data->pipes_count);
	data->pip = malloc(sizeof(*(data->pip)) * data->pipes_count);
	if (!data->pip)
	{
		write(1, "can not duing malloc\n", 22);
		return;
	}
	create_child(data);
	if (data->pid == 0)
		child_coneqt(data);
	if (data->pid > 0)
	{
		close_discriptor(data, 0, 2);
		while (data->cycle--)
		{
			wait(&data->error);
		}
		free(data->pip);
	}
}
