/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_for_oll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:30:54 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/10 15:30:57 by skeveyan         ###   ########.fr       */
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

void	join_for_oll(t_src *data)
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
