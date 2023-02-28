/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:47:23 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 16:48:00 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	unset(t_src *data)
{
	t_env	*cat_segment;
	int		n;

	n = 1;
	while (data->cl_in->word[n])
	{
		cat_segment = find_env(data->env, data->cl_in->word[n++]);
		if (cat_segment)
			delet_env(cat_segment);
	}
}
