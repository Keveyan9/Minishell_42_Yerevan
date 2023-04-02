/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:28:20 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/02 15:28:26 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_many_argument(void)
{
	printf("too many arguments  exit for minishell\n");
	data->error = 2;
}

void	exit_f(t_src *data)
{
	size_t	n;

	n = 0;
	if (!data->cl_in->word[2] && data->cl_in->word[1])
	{
		while (data->cl_in->word[1][n])
		{
			if (!ft_isdigit(data->cl_in->word[1][n++]))
			{
				printf("exit: %s: numeric argument..n", data->cl_in->word[1]);
				data->error = 2;
				break ;
			}
		}
		if (n == ft_strlen(data->cl_in->word[1]))
			data->error = ft_atoi(data->cl_in->word[1]);
		else
			data->error = 2;
	}
	else if (data->cl_in->word[2])
		exit_many_argument();
	oll_free(data);
	exit(data->error);
}
