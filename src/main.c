/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:50:44 by artadevo          #+#    #+#             */
/*   Updated: 2023/02/07 22:42:37 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_src	*data;

	(void)ac;
	(void)av;
	data = malloc (sizeof(t_src));
	if (!data)
		return (0);
	data = all_input(data, env);
	while (1)
	{
		data = start_input(data);
		ft_read_l(data);
		data = syntax_error(data);
	}
	return (0);
}
