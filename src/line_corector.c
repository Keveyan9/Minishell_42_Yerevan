/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_corector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:46:31 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/30 20:47:32 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	when_find_tokin(t_src *data, char *str, int *i, int j)
{
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	if (!str[*i])
	{
		str = ft_str_n_dup(data->line, j);
		free(data->line);
		data->line = str;
		return (1);
	}
	else if (char_tokin1(str, i) != 0)
	{
		str = ft_str_n_dup(data->line, j);
		free(data->line);
		data->line = str;
		return (1);
	}
	j = 0;
	return (0);
}

int	pipe_last(t_src *data, char *str, int j)
{
	int	l;

	l = j;
	if (str[l] == '|')
	{
		while (str[l] && str[++l] == 32)
			;
		if (!str[l])
		{
			str = ft_str_n_dup(data->line, j);
			free(data->line);
			data->line = str;
			data->syntax_err = '|';
			return (1);
		}
	}
	return (0);
}

void	syntax_last_nothing(t_src *data, int i, int j)
{
	char	*str;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	str = data->line;
	while (data && str && str[i])
	{
		j = i;
		if (pipe_last(data, str, j) == 1)
			return ;
		k = get_redir_syntax_err(str, &i);
		if (k != 0)
		{
			if (when_find_tokin(data, str, &i, j) != 0)
			{
				data->syntax_err = k;
				return ;
			}
			k = 0;
		}
		else
			i++;
	}
}
