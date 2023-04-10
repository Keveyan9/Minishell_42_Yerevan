/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t_clean2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:01:05 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/03 17:01:10 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	chek_push_word(t_tokens *token_list)
{
	if (!token_list->prev && token_list->type > 4 && token_list->type != 8)
		return (1);
	if (token_list->prev && (token_list->prev->type > 4
			|| token_list->prev->type == 0)
		&& token_list->prev->type != 8)
		return (1);
	if (token_list->prev->prev && token_list->prev->type == 8
		&& (token_list->prev->prev->type > 4
			|| token_list->prev->prev->type == 0))
		return (1);
	return (0);
}

static int	count_word_len(t_tokens *token_list)
{
	int	n;

	n = 0;
	if (token_list->type == 5 && !token_list->token)
		return (0);
	while (token_list && token_list->type != 0)
	{
		if (token_list && token_list->type > 4 && chek_push_word(token_list)
			&& token_list->type != 8)
		{
			while (token_list && token_list->type != 8)
				token_list = token_list->next;
			if (!token_list || token_list->type == 8)
				n++;
		}
		if (token_list)
			token_list = token_list->next;
	}
	return (n);
}

static void	qneqt_word(t_src *data, int n)
{
	char	*boxs;
	int		t;

	t = 0;
	boxs = NULL;
	while (data->token_list && data->token_list->type > 4
		&& data->token_list->type != 8)
	{
		chek_dolar_change(&data->token_list->token,
			data->token_list->type, data);
		boxs = ft_strjoin(data->cl_in->word[n], data->token_list->token);
		free_give_null (&(data->cl_in->word[n]));
		data->cl_in->word[n] = ft_strdup(boxs);
		free_give_null(&boxs);
		data->token_list = data->token_list->next;
	}
}

void	join_token_for_clean(t_src *data)
{
	int		n;

	n = count_word_len(data->token_list);
	if (n)
	{
		data->cl_in->word = ft_calloc(n + 1, sizeof (char *));
		if (!data->cl_in->word)
			return ;
	}
	n = 0;
	while (data->token_list && data->token_list->type != 0)
	{
		join_for_oll(data);
		if (data->token_list->type > 4
			&& data->token_list->type != 8 && chek_push_word(data->token_list))
			qneqt_word(data, n++);
		if (data->token_list)
			data->token_list = data->token_list->next;
	}
}
