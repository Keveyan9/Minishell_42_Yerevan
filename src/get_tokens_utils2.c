/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:26:29 by artadevo          #+#    #+#             */
/*   Updated: 2023/02/22 17:54:06 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_src	*find_redir_append(char *s, t_src *data)
{
	char	*tmp;

	(void)s;
	if (data->line[2])
	{
		data->token_list = new_node_tokens(">>",
				REDIR_APPEND, data->token_list);
		tmp = ft_substr(data->line, 2, ft_strlen(data->line));
	}
	else
	{
		data->token_list = new_node_tokens(">>",
				REDIR_APPEND, data->token_list);
		tmp = NULL;
	}
	free(data->line);
	data->line = tmp;
	return (data);
}

t_src	*find_hierdoc(char *s, t_src *data)
{
	char	*tmp;

	(void)s;
	if (data->line[2])
	{
		data->token_list = new_node_tokens("<<", HEREDOC, data->token_list);
		tmp = ft_substr(data->line, 2, ft_strlen(data->line));
	}
	else
	{
		data->token_list = new_node_tokens("<<", HEREDOC, data->token_list);
		tmp = NULL;
	}
	free(data->line);
	data->line = tmp;
	return (data);
}

t_src	*find_redir_in(char *s, t_src *data)
{
	char	*tmp;

	(void)s;
	if (data->line[1])
	{
		data->token_list = new_node_tokens("<", REDIR_IN, data->token_list);
		tmp = ft_substr(data->line, 1, ft_strlen(data->line));
	}
	else
	{
		data->token_list = new_node_tokens("<", REDIR_IN, data->token_list);
		tmp = NULL;
	}
	free(data->line);
	data->line = tmp;
	return (data);
}

t_src	*find_redir_out(char *s, t_src *data)
{
	char	*tmp;

	(void)s;
	if (data->line[1])
	{
		data->token_list = new_node_tokens(">", REDIR_OUT, data->token_list);
		tmp = ft_substr(data->line, 1, ft_strlen(data->line));
	}
	else
	{
		data->token_list = new_node_tokens(">", REDIR_OUT, data->token_list);
		tmp = NULL;
	}
	free(data->line);
	data->line = tmp;
	return (data);
}

//------verjum jnji --------
//-----VVVVVVVVVVVVV--------

void	print_tokens(t_src *data)
{
	t_tokens	*tmp;

	tmp = data->token_list;
	// while (tmp->prev != NULL)
	// {
	// 	tmp = tmp->prev;
	// }
	while (tmp)
	{
		printf("type = %d,\ttoken = %s,\tline = %d\n",tmp->type, tmp->token, tmp->len);
		tmp = tmp->next;
	}
}
