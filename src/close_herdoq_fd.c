/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_herdoq_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:16:20 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/02 15:16:35 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	close_herdoq_fd(t_src *data)
{

	data->cl_in = data->clin_head;
	while (data->cl_in)
	{
		if (data->cl_in->pip_her_doc[0] > 0)
		{
			close(data->cl_in->pip_her_doc[0]);
		}
		if (data->cl_in->pip_her_doc[1] > 0)
		{
			close(data->cl_in->pip_her_doc[1]);
		}
		data->cl_in = data->cl_in->next;
	}
	data->cl_in = data->clin_head;
}
