/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:33:07 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 16:33:11 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	env_f(t_src *data)
{
	t_env	*origin;

	origin = data->env;
	while (origin)
	{
		if (origin->value)
		printf("%s=%s\n", origin->key, origin->value);
		origin = origin->next;
	}
}
