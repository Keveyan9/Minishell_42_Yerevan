/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_fri.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:31:43 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 16:31:47 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	env_fri(t_env *fri_segment)
{
	free(fri_segment->key);
	free(fri_segment->value);
	free(fri_segment);
}
