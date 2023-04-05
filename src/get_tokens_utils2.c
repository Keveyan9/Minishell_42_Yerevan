/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:26:29 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/25 12:31:47 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_src	*find_redir_append(char *s, t_src *data)
{
	char	*tmp;

	(void)s;
	if (data->line[2])
	{
		data->token_list = new_node_tokens(ft_strdup(">>"),
				REDIR_APPEND, data->token_list);
		tmp = ft_substr(data->line, 2, ft_strlen(data->line));
	}
	else
	{
		data->token_list = new_node_tokens(ft_strdup(">>"),
				REDIR_APPEND, data->token_list);
		tmp = NULL;
	}
	free(data->line);
	data->line = NULL;
	data->line = tmp;
	return (data);
}

t_src	*find_hierdoc(char *s, t_src *data)
{
	char	*tmp;

	(void)s;
	if (data->line[2])
	{
		data->token_list = new_node_tokens(ft_strdup("<<"),
				HEREDOC, data->token_list);
		tmp = ft_substr(data->line, 2, ft_strlen(data->line));
	}
	else
	{
		data->token_list = new_node_tokens(ft_strdup("<<"),
				HEREDOC, data->token_list);
		tmp = NULL;
	}
	free(data->line);
	data->line = NULL;
	data->line = tmp;
	return (data);
}

t_src	*find_redir_in(char *s, t_src *data)
{
	char	*tmp;

	(void)s;
	if (data->line[1])
	{
		data->token_list = new_node_tokens(ft_strdup("<"),
				REDIR_IN, data->token_list);
		tmp = ft_substr(data->line, 1, ft_strlen(data->line));
	}
	else
	{
		data->token_list = new_node_tokens(ft_strdup("<"),
				REDIR_IN, data->token_list);
		tmp = NULL;
	}
	free(data->line);
	data->line = NULL;
	data->line = tmp;
	return (data);
}

t_src	*find_redir_out(char *s, t_src *data)
{
	char	*tmp;

	(void)s;
	if (data->line[1])
	{
		data->token_list = new_node_tokens(ft_strdup(">"),
				REDIR_OUT, data->token_list);
		tmp = ft_substr(data->line, 1, ft_strlen(data->line));
	}
	else
	{
		data->token_list = new_node_tokens(ft_strdup(">"),
				REDIR_OUT, data->token_list);
		tmp = NULL;
	}
	free(data->line);
	data->line = NULL;
	data->line = tmp;
	return (data);
}