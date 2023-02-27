/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:15:07 by artadevo          #+#    #+#             */
/*   Updated: 2023/01/22 20:11:09 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_src *ft_parser(t_src *data)
{
	int i;
	char *s;

	i = -1;
	s = data->line;
	while (s[++i])
	{
		// if (ft_strchr_mod(s, 39) && check_cuote(s, 39))
		// 	i++;
	}
	return (data);
}
