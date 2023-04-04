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
	file_discriptor(data);
	//change_fd(data);
	if (data->cl_in->pip_her_doc[1] > 0)
	{
		close(data->cl_in->pip_her_doc[1]);
	}
	if (data->cl_in->pip_her_doc[0] > 0)
	{
		close(data->cl_in->pip_her_doc[0]);
	}
	if (chek_coll_builtin(data) == 0)
		;
	else
		coll_comands(data);
}
