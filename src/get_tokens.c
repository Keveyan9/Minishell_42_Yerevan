/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:37:41 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/05 20:04:41 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_src	*get_tokens(t_src *data)
{
	while (data->line)
	{
		if ((int)data->line[0] == ' ')
			data = find_space(data->line, data);
		else if ((int)data->line[0] == '|')
			data = find_pipe(data->line, data);
		else if ((int)data->line[0] == '\'')
			data = find_single_quotes(data->line, data);
		else if ((int)data->line[0] == '\"')
			data = find_duobl_quotes(data->line, data);
		else if ((int)data->line[0] == '>' && (int)data->line[1] == '>')
			data = find_redir_append(data->line, data);
		else if ((int)data->line[0] == '<' && (int)data->line[1] == '<')
			data = find_hierdoc(data->line, data);
		else if ((int)data->line[0] == '<')
			data = find_redir_in(data->line, data);
		else if ((int)data->line[0] == '>')
			data = find_redir_out(data->line, data);
		else
			data = find_word(data->line, data);
	}
	return (data);
}

t_tokens	*new_node_tokens(char *s, int k, t_tokens *token_list)
{
	t_tokens	*node;
	int			i;

	i = 0;
	node = (t_tokens *)malloc(sizeof(t_tokens));
	if (!node)
		return (0);
	node->len = (int)ft_strlen(s);
	node->token = s;
	node->type = k;
	node->next = NULL;
	node->prev = token_list;
	if (token_list)
		token_list->next = node;
	return (node);
}

void	tokens_list_start(t_src *data)
{
	t_tokens	*tmp;

	tmp = data->token_list;
	while (tmp && tmp->prev)
		tmp = tmp->prev;
	data->token_list = tmp;
}

void	tokens_list_last(t_src *data)
{
	t_tokens	*tmp;

	tmp = data->token_list;
	while (tmp && tmp->next)
		tmp = tmp->next;
	data->token_list = tmp;
}
