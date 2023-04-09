/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:42:53 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/26 17:51:11 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	find_word_equal(t_src *data, int i, char **line)
{
	*line = ft_substr(data->line, 0, i + 1);
	data->token_list = new_node_tokens(*line, WORD, data->token_list);
}

t_src	*find_word(char *s, t_src *data)
{
	char	*tmp;
	char	*line;
	int		i;
	int		k;

	i = 0;
	tmp = NULL;
	line = NULL;
	k = ft_strlen(data->line);
	while (s[i] && s[i] != ' ' && s[i] != '<'
		&& s[i] != '>' && s[i] != '|' && s[i] != '\'' && s[i] != '\"')
		i++;
	if (i < k)
	{
		line = ft_substr(data->line, 0, i);
		data->token_list = new_node_tokens(line, WORD, data->token_list);
		tmp = ft_substr(data->line, i, k);
	}
	else if (i == k)
		find_word_equal(data, i, &line);
	free_give_null(&data->line);
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
	{
		i++;
		while (s[i] && s[i] != '\"')
			i++;
	}
	data->token_list = new_node_tokens(ft_substr(data->line, 1, i - 1),
			EXP_QUOTES_DOUBL, data->token_list);
	tmp = ft_substr(data->line, i + 2, k);
	free_give_null(&data->line);
	data->line = tmp;
	return (data);
}
