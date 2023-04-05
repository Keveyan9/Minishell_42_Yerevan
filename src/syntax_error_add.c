/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:10:31 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/30 23:53:34 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	get_pipe_syntax_err(char tokin)
{
	if (tokin)
	{
		if (tokin == '|')
			return ('|');
		if (tokin == ';')
			return (';');
		if (tokin == ')')
			return (')');
	}
	return (0);
}

int	char_tokin1_norm(char *tokin, int *i)
{
	if (tokin && tokin[*i] && tokin[*i] == '|')
	{
		*i += 1;
		return (1);
	}
	if (tokin && tokin[*i] && tokin[*i] == '>'
		&& tokin[*i + 1] && tokin[*i + 1] == '>')
	{
		*i += 2;
		return (6);
	}
	return (0);
}

int	char_tokin1(char *tokin, int *i)
{
	int	l;

	l = char_tokin1_norm(tokin, i);
	if (l > 0)
		return (l);
	if (tokin && tokin[*i] && tokin[*i] == '<'
		&& tokin[*i + 1] && tokin[*i + 1] == '<')
	{
		*i += 2;
		return (7);
	}
	if (tokin && tokin[*i] && tokin[*i] == '<')
	{
		*i += 1;
		return (8);
	}
	if (tokin && tokin[*i] && tokin[*i] == '>')
	{
		*i += 1;
		return (5);
	}
	return (0);
}

int	get_redir_syntax_err(char *tokin, int *i)
{
	if (tokin && tokin[*i] && tokin[*i] == '>'
		&& tokin[*i + 1] && tokin[*i + 1] == '>')
	{
		*i += 2;
		return (150);
	}
	if (tokin && tokin[*i] && tokin[*i] == '<'
		&& tokin[*i + 1] && tokin[*i + 1] == '<')
	{
		*i += 2;
		return (150);
	}
	if (tokin && tokin[*i] && tokin[*i] == '<')
	{
		*i += 1;
		return (150);
	}
	if (tokin && tokin[*i] && tokin[*i] == '>')
	{
		*i += 1;
		return (150);
	}
	return (0);
}

void	add_sintex_error(t_src *data)
{
	t_tokens	*tmp;

	tmp = data->token_list;
	while (tmp && tmp->next != NULL)
	{
		if (tmp->type == 0)
			data->pipes_count += 1;
		tmp = tmp->next;
	}
}
