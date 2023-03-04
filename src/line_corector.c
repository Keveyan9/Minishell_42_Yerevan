/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_corector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:46:31 by artadevo          #+#    #+#             */
/*   Updated: 2023/02/20 23:11:10 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int get_start(const char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] != ' ')
			return (i);
	return (0);
}

static int get_end(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (str[i] != ' ')
			return (i);
		i--;
	}
	return (0);
}

char *line_corector(char *line)
{
	int start;
	int end;
	char *tmp;

	start = get_start(line);
	end = get_end(line);
	tmp = ft_str_env_cmp(line, start, end);
	free(line);
	return (tmp);
}
