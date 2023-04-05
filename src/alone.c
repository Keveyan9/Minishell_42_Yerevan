/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:08:26 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/02 15:08:37 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_builtin(t_src *data)
{
	if ((ft_strlen(data->cl_in->word[0]) == 4)
		&& (ft_strncmp(data->cl_in->word[0], "echo", 4) == 0))
		return (1);
	else if (ft_strlen(data->cl_in->word[0]) == 2
		&& ft_strncmp(data->cl_in->word[0], "cd", 2) == 0)
		return (1);
	else if (ft_strlen(data->cl_in->word[0]) == 3
		&& ft_strncmp(data->cl_in->word[0], "pwd", 3) == 0)
		return (1);
	else if (ft_strlen(data->cl_in->word[0]) == 6
		&& ft_strncmp(data->cl_in->word[0], "export", 6) == 0 )
		return (1);
	else if (ft_strlen(data->cl_in->word[0]) == 5
		&& ft_strncmp(data->cl_in->word[0], "unset", 5) == 0 )
		return (1);
	else if (ft_strlen(data->cl_in->word[0]) == 3
		&& ft_strncmp(data->cl_in->word[0], "env", 3) == 0 )
		return (1);
	else if (ft_strlen(data->cl_in->word[0]) == 4
		&& ft_strncmp(data->cl_in->word[0], "exit", 4) == 0)
		return (1);
	return (0);
}

static void	chanch_back_main_fd(t_src *data)
{
	change_fd(data);
	chek_coll_builtin(data);
	if (data->cl_in->pip_her_doc[0] > 0)
	{	
		dup2(data->main_fd_0, 0);
		close(data->cl_in->pip_her_doc[0]);
		data->cl_in->pip_her_doc[0] = -1;
	}
	else
		close(data->main_fd_0);
	if (data->cl_in->pip_her_doc[1] > 0)
	{
		dup2(data->main_fd_1, 1);
		close(data->cl_in->pip_her_doc[1]);
		data->cl_in->pip_her_doc[1] = -1;
	}
	else
		close(data->main_fd_1);
}

void	alone(t_src *data)
{
	if (is_builtin(data))
	{
		data->main_fd_0 = dup(0);
		data->main_fd_1 = dup(1);
		file_discriptor(data);
		if (!g_flags)
			chanch_back_main_fd(data);
		else
		{
			close(data->main_fd_1);
			close(data->main_fd_0);
		}
		close_herdoq_fd(data);
	}
	else
		alone_child(data);
}
