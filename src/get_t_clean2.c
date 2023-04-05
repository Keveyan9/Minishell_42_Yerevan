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

static void	add_tab(t_src *data)
{
	char	*box;

	box = NULL;
	if (data->token_list->type < 5 && data->token_list->next
		&& data->token_list->next->type > 4
		&& data->token_list->next->type != 8)
	{
		box = ft_strdup(data->cl_in->oll);
		free (data->cl_in->oll);
		data->cl_in->oll = NULL;
		data->cl_in->oll = ft_strjoin(box, " ");
		free (box);
	}
}

static void	join_for_oll(t_src *data)
{
	char	*box;

	box = NULL;
	add_tab(data);
	if (data->token_list->type == 6 || data->token_list->type == 7)
	{
		box = ft_strdup(data->cl_in->oll);
		free(data->cl_in->oll);
		data->cl_in->oll = NULL;
		data->cl_in->oll = ft_strjoin(box, "31");
		free(box);
	}
	box = ft_strdup(data->cl_in->oll);
	free(data->cl_in->oll);
	data->cl_in->oll = ft_strjoin(box, data->token_list->token);
	free(box);
	box = NULL;
	if (data->token_list->type < 5 && data->token_list->next
		&& data->token_list->next->type == 8)
		data->token_list = data->token_list->next;
}

static void	for_word_split(t_src *data, char **for_word)
{
	data->cl_in->word = ft_split(*for_word, ' ');
	free(*for_word);
	for_word = NULL;
}

static int	chek_push_word(t_src *data)
{
	if (!data->token_list->prev)
		return (1);
	if (data->token_list->prev && (data->token_list->prev->type > 4
			|| data->token_list->prev->type == 0)
		&& data->token_list->prev->type != 8)
		return (1);
	if (data->token_list->prev->prev && data->token_list->prev->type == 8
		&& (data->token_list->prev->prev->type > 4
			|| data->token_list->prev->prev->type == 0))
		return (1);
	return (0);
}

void	join_token_for_clean(t_src *data)
{
	char	*boxs;
	char	*for_word;

	boxs = NULL;
	for_word = NULL;
	while (data->token_list && data->token_list->type != 0)
	{
		join_for_oll(data);
		if (data->token_list->type > 4 && chek_push_word(data))
		{
			boxs = ft_strdup(for_word);
			free(for_word);
			for_word = NULL;
			chek_dolar_change(data->env, &data->token_list->token,
				data->token_list->type);
			for_word = ft_strjoin(boxs, data->token_list->token);
			free(boxs);
			boxs = NULL;
		}
		data->token_list = data->token_list->next;
	}
	if (for_word)
		for_word_split(data, &for_word);
}
