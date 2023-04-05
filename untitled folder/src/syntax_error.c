/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:30:42 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/30 22:51:02 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	is_len_delet_spaces(t_src *data, char *s)
{
	int		i;
	char	*d;

	i = 0;
	if (data && s && s[i] == ' ')
	{
		while (data && s && s[i] == ' ')
			i++;
	}
	d = ft_strdup(data->line);
	free(data->line);
	data->line = 0;
	data->line = ft_strjoin(&d[i], "");
	free(d);
	d = 0;
}

int	syntacs_error_redir(char *str, t_src *data, int i)
{
	if (get_redir_syntax_err(str, &i) != 0)
	{
		while (str && str[i] && str[i] == 32)
		i++;
		if (!str[i])
		{
			data->syntax_err = 150;
			return (1);
		}
	}
	return (0);
}

void	get_pipe_syntax_err2(t_src *data, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i])
	{
		if (str[i] == '|')
		{
			j = i;
			i++;
			while (str && str[i] && str[i] == 32)
			i++;
			if (!str[i] || (str[i] && str[i] == '|'))
			{
				data->syntax_err = '|';
				new_line(data, j - 1, '|');
			}
		}
		i++;
	}
}

int	syntax_error_search(t_src *data)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = data->line;
	if (data && str)
	{
		if (str && str[i] && get_pipe_syntax_err(str[i]) != 0)
		{
			data->syntax_err = get_pipe_syntax_err(str[i]);
			return (1);
		}
		if (syntacs_error_redir(str, data, i) == 1)
			return (1);
		get_pipe_syntax_err2(data, str);
		check_quots(data);
		syntax_last_nothing(data, i, j);
	}
	return (0);
}

t_src	*syntax_error(t_src *data)
{
	is_len_delet_spaces(data, data->line);
	if (data->line[0] == '|')
	{
		get_frst_element(data);
		return (data);
	}
	if (syntax_error_search(data))
	{
		return (data);
	}
	data = get_tokens(data);
	add_sintex_error(data);
	return (data);
}
