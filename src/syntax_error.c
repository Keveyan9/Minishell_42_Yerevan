/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:30:42 by artadevo          #+#    #+#             */
/*   Updated: 2023/02/04 17:56:45 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	get_index_quotes(t_src *data)
{
	int		i;

	i = 0;
	if (!data->doubl_quotes && !data->single_quotes)
		i = 0;
	else if (data->doubl_quotes && data->single_quotes)
	{
		if (data->doubl_quotes > data->single_quotes)
			i = data->single_quotes;
		else
			i = data->doubl_quotes;
	}
	else if (data->doubl_quotes && !data->single_quotes)
		i = data->doubl_quotes;
	else if (!data->doubl_quotes && data->single_quotes)
		i = data->single_quotes;
		data->syntax_err = i;
	return (i);
}

int	check_and_break_parentheses(t_src *data)
{
	int	i;

	i = -1;
	while (data->line[++i] && i <= (int)ft_strlen(data->line))
	{
		if (data->line[i] == '\'')
		{
			data->single_quotes = i;
			i++;
			if (ft_strchr_mod(data->line + i, '\'') || data->line[i] == '\'')
				data->single_quotes = 0;
			i += ft_strchr_mod(data->line + i, '\'');
		}
		else if (data->line[i] == '\"')
		{
			data->doubl_quotes = i;
			i++;
			if (ft_strchr_mod(data->line + i, '\"') || data->line[i] == '\"')
				data->doubl_quotes = 0;
			i += ft_strchr_mod(data->line + i, '\"');
		}
	}
	return (get_index_quotes(data));
}

t_src	*syntax_error(t_src *data)
{
	data->line = line_corector(data->line);
	if (data->line[0] == '|' || data->line[0] == ')' || data->line[0] == ';')
		printf(" syntax error near unexpected token `|;)\n"); // grel exit funkcia
	if (check_and_break_parentheses(data))
		printf(" syntax error near unexpected token `\'\"\n"); // grel exit funkcia
	return (data);
}
