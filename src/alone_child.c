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
	pid_t	pid;

	pid = 0;
	pid = fork();
	if (pid < 0)
		write(1, "can not creat child\n", 20);
	else if (pid == 0)
	{
		coll_comands(data);
		oll_free(data);
		exit(0);
	}
	wait(0);
	return(0);
}
