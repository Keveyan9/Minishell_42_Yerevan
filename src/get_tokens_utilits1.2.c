/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:11:36 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/02 15:11:59 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"minishell.h"

#include"minishell.h"

t_src	*find_space(char *s, t_src *data)
{
	char	*tmp;
	int		i;
	int		k;

	i = 0;
	k = ft_strlen(data->line);
	while (s[i] && s[i] == ' ')
		i++;
	data->token_list = new_node_tokens(ft_strdup(" "), SPAC, data->token_list);
	tmp = ft_substr(data->line, i, k);
	free_give_null(&data->line);
	data->line = tmp;
	return (data);
}

t_src	*find_pipe(char *s, t_src *data)
{
	char	*tmp;

	(void)s;
	data->token_list = new_node_tokens(ft_strdup("|"), PIPE, data->token_list);
	if (data->line[1])
		tmp = ft_substr(data->line, 1, (ft_strlen(data->line) - 1));
	else
		tmp = NULL;
	free_give_null(&data->line);
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
	}
	free_give_null(&data->line);
	data->line = tmp;
	return (data);
}