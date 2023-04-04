/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolar_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:25:21 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/02 15:25:28 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dolar_change(t_env *env, char **key, int n)
{
	t_env	*plase_key;

	plase_key = find_env(env, &((*key)[n]));
	if (!plase_key)
	{
		free(*key);
		*key = ft_strdup("\n");
	}
	else
	{
		free(*key);
		*key = ft_strdup(plase_key->value);
	}
	return ;
}
