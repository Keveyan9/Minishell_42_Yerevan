/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:50:44 by artadevo          #+#    #+#             */
/*   Updated: 2023/01/20 23:02:28 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_src	*data;

	(void)ac;
	(void)av;
	data = malloc (sizeof(t_src));
	if (!data)
		return (0);
	data = start_input(data, env);
	while (1)
	{
		ft_read_l(data);
		data = find_syntax_error(data);
	}
	return (0);
}
