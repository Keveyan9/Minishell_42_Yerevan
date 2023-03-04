/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:41:13 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 16:41:22 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	free_env(t_src *data)
{
	while (data->env)
	{
		if (data->env->key)
			free(data->env->key);
		if (data->env->value)
			free(data->env->value);
		if (data->env->next != NULL)
		{
			data->env = data->env->next;
			free(data->env->prev);
		}
		else
		{
			free(data->env);
			break ;
		}
	}
}
