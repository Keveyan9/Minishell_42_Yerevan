/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:41:57 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/02 15:42:05 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

void	logic(t_src *data)
{
	t_cl_in *origin;

	origin = data->cl_in;
	file_discriptor(data);
	change_fd(data);
	close_discriptor(data);
	close_herdoq_fd(data);
	data->cl_in = origin;
	if (chek_coll_builtin(data) == 0)
		;
	else
		coll_comands(data);
	oll_free(data);
	exit(data->error);
}