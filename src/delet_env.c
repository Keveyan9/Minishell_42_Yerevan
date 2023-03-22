/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delet_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:19:48 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 16:19:50 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	delet_env(t_env *cat_segment)
{
	// t_env	*origin;

	// origin = cat_segment;
	if (cat_segment->next)
		cat_segment->next->prev = cat_segment->prev;
	if (cat_segment->prev)
		cat_segment->prev->next = cat_segment->next;
	env_fri(cat_segment);
}
