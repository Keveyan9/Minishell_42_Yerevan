/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oll_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:42:34 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 16:42:45 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	oll_free(t_src *data)
{
	if (data->line)
	{
		free(data->line);
		data->line = NULL;
	}
	if (data->home_path)
	{
		free(data->home_path);
		data->home_path = NULL;
	}
	if (data->env)
		free_env(data);
	if (data->cl_in)
		free_clin(data);
	free(data);
	data = NULL;
}
