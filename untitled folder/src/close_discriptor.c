/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_discriptor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:15:51 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/02 15:16:01 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	close_discriptor(t_src *data)
{
	int	n;

	n = 0;
	while (n < data->pipes_count)
	{
		close(data->pip[n][0]);
		close(data->pip[n++][1]);
	}
}
