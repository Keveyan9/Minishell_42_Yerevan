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

	pip_eror = 0;
	data->cycle = 0;
	int n = 0;
	while ( data->pid > 0 && data->pipes_count >= data->cycle)
	{
		if (data->pipes_count > data->cycle)
		{
			pip_eror == pipe(data->pip[data->cycle]);
		//usleep(10);
			if (pip_eror != 0)
			{
				exit(11);
				perror("pip");
				break;
			}
			data->pip_doing++;
		}
		data->pid = fork();
		if (data->pid > 0 )
		{
			//data->cl_in = data->cl_in->next;
			data->cycle++;
		}
		if (data->pid < 0)
		{
			exit(11);
			perror(" child problems ");
			break;
		}
	}
}

void realaysing(t_src *data)
{
	printf("_______________________%d______________\n",data->pipes_count);
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
		close_discriptor(data,0,2);
	 	while (data->cycle--)
	 	{
	 		wait(&data->error);
	 	}
		free(data->pip);
	 }
}
