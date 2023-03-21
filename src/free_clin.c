/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_clin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:40:23 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 16:40:34 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	free_clin(t_src *data)
{
	while (data->cl_in->prev)
		data->cl_in = data->cl_in->prev;
	printf("@_%s__@\n",data->cl_in->id);
	while (data->cl_in)
	{
		if (data->cl_in->id)
		{
			free(data->cl_in->id);
			data->cl_in->id = NULL;
		}
		if (data->cl_in->word)
		{
			frik(data->cl_in->word);
			data->cl_in->word = NULL;
		}
		if (data->cl_in->oll)
		{
			free(data->cl_in->oll);
			data->cl_in->oll = NULL;
		}
		if(data->cl_in->next)
		{
			data->cl_in = data->cl_in->next;
			free(data->cl_in->prev);
			data->cl_in->prev = NULL ;
		}
		else
		{
			free(data->cl_in);
			data->cl_in = NULL;
			break ;
		}
	}
}
