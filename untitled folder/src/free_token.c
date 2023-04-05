/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:36:44 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/02 15:36:46 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_token(t_src *data)
{
	data->token_list = data->tokens_head;
	while (data->token_list)
	{
		if (data->token_list->token)
		{
			free(data->token_list->token);
			data->token_list->token = NULL;
		}
		if (data->token_list->next)
		{
			data->token_list = data->token_list->next;
			free(data->token_list->prev);
			data->token_list->prev = NULL;
		}
		else
		{
			free(data->token_list);
			break ;
		}
	}
}
