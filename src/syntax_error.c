/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:30:42 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/04 21:58:20 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int get_count(char *s, char c)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] == c)
			count++;
	}
	return (count);
}

static int get_index_quotes_2(t_src *data)
{
	int i;

	i = 0;
	if (data->doubl_quotes > data->single_quotes)
		i = data->single_quotes;
	else
		i = data->doubl_quotes;
	return (i);
}

int get_index_quotes(t_src *data)
{
	int i;

	i = 0;
	if (!data->doubl_quotes && !data->single_quotes)
	{
		i = 0;
		if ((data->line[0] == '\'' || data->line[0] == '\"') && (get_count(data->line, '\'') == 1 || get_count(data->line, '\"') == 1))
		{
			i = -1;
			data->index_s_err = 0;
		}
	}
	else if (data->doubl_quotes && data->single_quotes)
		i = get_index_quotes_2(data);
	else if (data->doubl_quotes && !data->single_quotes)
		i = data->doubl_quotes;
	else if (!data->doubl_quotes && data->single_quotes)
		i = data->single_quotes;
	if (i >= 0)
		data->index_s_err = i;
	data->syntax_err = (int)(data->line[data->index_s_err]);
	return (i);
}

int check_and_break_parentheses(t_src *data)
{
	int i;

	i = -1;
	while (data->line[++i] && i <= (int)ft_strlen(data->line))
	{
		if (data->line[i] == '\'')
		{
			data->single_quotes = i++;
			if (ft_strchr_mod(data->line + i, '\'') || data->line[i] == '\'')
				data->single_quotes = 0;
			i += ft_strchr_mod(data->line + i, '\'');
			if (data->single_quotes != 0)
				data->index_s_err = i;
		}
		else if (data->line[i] == '\"')
		{
			data->doubl_quotes = i++;
			if (ft_strchr_mod(data->line + i, '\"') || data->line[i] == '\"')
				data->doubl_quotes = 0;
			i += ft_strchr_mod(data->line + i, '\"');
			if (data->doubl_quotes != 0)
				data->index_s_err = i;
		}
	}
	return (get_index_quotes(data));
}

t_src *syntax_error(t_src *data)
{
	data->line = line_corector(data->line);
	if (data->line[0] == '|' || data->line[0] == ')' || data->line[0] == ';')
	{
		get_frst_element(data->line, data);
		print_eyntax_err(data); // grel exit funkcia
		return (data);
	}
	if (check_and_break_parentheses(data))
	{
		print_eyntax_err(data); // grel exit funkcia
		return (data);
	}	 data = get_tokens(data);
	  add_sintex_error(data);
	return (data);
}
