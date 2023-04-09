/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:11:36 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/02 15:11:59 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	change_fd(t_src *data)
{
	if (data->cl_in->pip_her_doc[0] > 0)
	{
		dup2(data->cl_in->pip_her_doc[0], 0);
		close(data->cl_in->pip_her_doc[0]);
	}
	if (data->cl_in->pip_her_doc[1] > 0)
	{
		dup2(data->cl_in->pip_her_doc[1], 1);
		close(data->cl_in->pip_her_doc[1]);
	}
}

void	change_fd_main(t_src *data)
{
	if (data->cl_in->pip_her_doc[0] > 0)
	{
		data->main_fd_0 = dup(0);
		dup2(data->cl_in->pip_her_doc[0], 0);
	}
	if (data->cl_in->pip_her_doc[1] > 0)
	{
		data->main_fd_1 = dup(1);
		dup2(data->cl_in->pip_her_doc[1], 1);
	}
}
