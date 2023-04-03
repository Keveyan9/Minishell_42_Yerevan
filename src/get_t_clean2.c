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

static void	join_for_oll(t_src *data)
{
	char	*boxs;

	boxs = NULL;
	if (data->token_list->type < 5 && data->token_list->next->type == 8)
		data->token_list = data->token_list->next;
	if (data->token_list->type == 6 || data->token_list->type == 7)
	{
		boxs = ft_strdup(data->cl_in->oll);
		free(data->cl_in->oll);
		data->cl_in->oll = NULL;
		data->cl_in->oll = ft_strjoin(boxs, "'");
		free(boxs);
	}
	boxs = ft_strdup(data->cl_in->oll);
	free(data->cl_in->oll);
	data->cl_in->oll = ft_strjoin(boxs, data->token_list->token);
	free(boxs);
	boxs = NULL;
}

static void	for_word_split(t_src *data, char **for_word)
{
	data->cl_in->word = ft_split(*for_word, ' ');
	free(*for_word);
	for_word = NULL;
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
		if (!(data->token_list->type > 0 && data->token_list->type < 5)
			&& ((data->token_list->prev && data->token_list->prev->type > 4)
				|| !data->token_list->prev))
		{
			boxs = ft_strdup(for_word);
			free(for_word);
			for_word = NULL;
			if (data->token_list->token[0] == '$' && data->token_list->token[1])
				dolar_change (data->env, &data->token_list->token, 1);
			for_word = ft_strjoin(boxs, data->token_list->token);
			free(boxs);
			boxs = NULL;
		}
		data->token_list = data->token_list->next;
	}
	if (for_word)
		for_word_split(data, &for_word);
}
