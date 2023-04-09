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
		free_give_null(&data->cl_in->oll);
		data->cl_in->oll = ft_strjoin(box, "'");
		free_give_null(&box);
	}
	box = ft_strdup(data->cl_in->oll);
	free(data->cl_in->oll);
	data->cl_in->oll = ft_strjoin(box, data->token_list->token);
	free_give_null(&box);
	if (data->token_list->type == 6 || data->token_list->type == 7)
	{
		box = ft_strdup(data->cl_in->oll);
		free_give_null(&data->cl_in->oll);
		data->cl_in->oll = ft_strjoin(box, "'");
		free_give_null(&box);
	}
	if (data->token_list->type < 5 && data->token_list->next
		&& data->token_list->next->type == 8)
		data->token_list = data->token_list->next;
}

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
		if (token_list->type > 4 && chek_push_word(token_list)
			&& token_list->type != 8)
			n++;
		token_list = token_list->next;
	}
	return (n);
}

void	join_token_for_clean(t_src *data)
{
	int	n;
	int stop;

	stop = 1;
	n = count_word_len(data->token_list);
	if (n)
	{
		data->cl_in->word = (char **)malloc(sizeof(char *) * (n + 1));
		if (!data->cl_in->word)
			return ;
		data->cl_in->word[n] = NULL;
	}
	n = 0;
	while (data->token_list && data->token_list->type != 0)
	{
		// if (data->token_list->type < 5)
		// 	stop = 0;
		// if (data->token_list->type == 8)
		// 	stop = 1;
		join_for_oll(data);
		if (data->token_list->type > 4 && stop
			&& data->token_list->type != 8 && chek_push_word(data->token_list))
		{
			chek_dolar_change(data->env, &data->token_list->token,
				data->token_list->type, data);
			data->cl_in->word[n++] = ft_strdup(data->token_list->token);
		}
		//if (data->token_list)
			data->token_list = data->token_list->next;
	}
}
