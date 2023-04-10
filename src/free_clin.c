/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_clin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:40:23 by skeveyan          #+#    #+#             */
/*   Updated: 2023/03/26 17:55:26 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static void	free_clin_half(t_src *data)
{
	if (data->cl_in->word)
	{
		printf("word\n");
		frik(data->cl_in->word);
		data->cl_in->word = NULL;
	}
	if (data->cl_in->oll)
	{
		printf("oll\n");
		free(data->cl_in->oll);
		data->cl_in->oll = NULL;
	}
}

void	free_clin(t_src *data)
{
	data->cl_in = data->clin_head;
	while (data->cl_in)
	{
		free_clin_half(data);
		if (data->cl_in->next)
		{
			printf("next\n");
			data->cl_in = data->cl_in->next;
			free(data->cl_in->prev);
			data->cl_in->prev = NULL ;
		}
		else
		{
			printf("clin\n");
			free(data->cl_in);
			data->cl_in = NULL;
			break ;
		}
	}
}
