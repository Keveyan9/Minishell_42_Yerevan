/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_close_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:16:44 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/10 20:16:48 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	clean_close_name(char **close_name, int *fl_doing_dolar)
{
	char	*box;
	char	*start;
	int		n;

	n = 0;
	while ((*close_name)[n])
	{
		if ((*close_name)[n] == '\'')
		{	
			start = ft_substr(*close_name, 0, n);
			box = ft_substr(*close_name, n + 1, ft_strlen(*close_name));
			free_give_null(close_name);
			*close_name = ft_strjoin(start, box);
			free_give_null(&start);
			free_give_null(&box);
			*fl_doing_dolar = 1;
		}
		n++;
	}
}
