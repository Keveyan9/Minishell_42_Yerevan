/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:39:41 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 16:40:01 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

t_env	*find_env(t_env *env, char *s)
{
	while (env)
	{
		if (ft_strncmp(s, env->key, ft_strlen(s)) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}
