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

	data->pid = 0;
	data->pid = fork();
	int d;

	d = 0;
	if (data->pid < 0)
		write(1, "can not creat child\n", 20);
	else if (data->pid == 0)
	{	
		coll_comands(data);
		oll_free(data);
	}
	else if (data->pid > 0)
	{
		 wait(&d);
		data->error = WEXITSTATUS(d);
		return(0);
	}
	oll_free(data);
	exit(data->error);
}
