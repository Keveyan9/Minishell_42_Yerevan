/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:42:53 by artadevo          #+#    #+#             */
/*   Updated: 2023/02/20 21:32:15 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_src	*find_word(char *s, t_src *data)
{
	char	*tmp;
	int		i;
	int		k;

	i = 0;
	tmp = NULL;
	k = ft_strlen(data->line);
	while (s[i] && s[i] != ' ' && s[i] != '<' && s[i] != '>' && s[i] != '|'
		&& s[i] != '\'' && s[i] != '\"')
		i++;
	if (i < k)
	{
		data->token_list = new_node_tokens(ft_substr(data->line, 0, i),
				WORD, data->token_list);
		tmp = ft_substr(data->line, i, k);
	}
	else if (i == k)
	{
		data->token_list = new_node_tokens(ft_substr(data->line, 0, i + 1),
				WORD, data->token_list);
		tmp = NULL;
	}
	free(data->line);
	data->line = tmp;
	return (data);
}

t_src	*find_space(char *s, t_src *data)
{
	char	*tmp;
	int		i;
	int		k;

	i = 0;
	k = ft_strlen(data->line);
	while (s[i] && s[i] == ' ')
		i++;
	data->token_list = new_node_tokens(" ", SPAC, data->token_list);
	tmp = ft_substr(data->line, i, k);
	free(data->line);
	data->line = tmp;
	return (data);
}

t_src	*find_pipe(char *s, t_src *data)
{
	char	*tmp;

	(void)s;
	data->token_list = new_node_tokens("|", PIPE, data->token_list);
	if (data->line[1])
		tmp = ft_substr(data->line, 1, (ft_strlen(data->line) - 1));
	else
		tmp = NULL;
	free(data->line);
	data->line = tmp;
	return (data);
}

t_src	*find_single_quotes(char *s, t_src *data)
{
	char	*tmp;
	int		i;
	int		k;

	i = 0;
	tmp = NULL;
	k = ft_strlen(data->line);
	if (s[i] == '\'')
		i++;
	while (s[i] && s[i] != '\'')
		i++;
	if (i < k)
	{
		data->token_list = new_node_tokens(ft_substr(data->line, 1, i - 1),
				EXP_QUOTES_SINGLE, data->token_list);
		tmp = ft_substr(data->line, i + 1, k);
	}
	else if (i == k)
	{
		data->token_list = new_node_tokens(ft_substr(data->line, 1, i - 1),
				EXP_QUOTES_SINGLE, data->token_list);
		tmp = NULL;
	}
	free(data->line);
	data->line = tmp;
	return (data);
}

t_src	*find_duobl_quotes(char *s, t_src *data)
{
	char	*tmp;
	int		i;
	int		k;

	i = 0;
	tmp = NULL;
	k = ft_strlen(data->line);
	if (s[i] == '\"')
		i++;
	while (s[i] && s[i] != '\"')
		i++;
	if (i < k)
	{
		data->token_list = new_node_tokens(ft_substr(data->line, 1, i - 1),
				EXP_QUOTES_DOUBL, data->token_list);
		tmp = ft_substr(data->line, i + 1, k);
	}
	else if (i == k)
	{
		data->token_list = new_node_tokens(ft_substr(data->line, 1, i - 1),
				EXP_QUOTES_DOUBL, data->token_list);
		tmp = NULL;
	}
	free(data->line);
	data->line = tmp;
	return (data);
}
