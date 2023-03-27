/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:41:13 by skeveyan          #+#    #+#             */
/*   Updated: 2023/03/26 17:55:43 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_env(t_src *data)
{
	while (data->env->prev)
		data->env = data->env->prev;
	while (data->env)
	{
		if (data->env->key)
			free(data->env->key);
		if (data->env->value)
			free(data->env->value);
		if (data->env->next != NULL)
		{
			data->env = data->env->next;
			if (data->env->prev)
				free(data->env->prev);
		}
		else
		{
			if (data->env)
				free(data->env);
			break ;
		}
	}
}
