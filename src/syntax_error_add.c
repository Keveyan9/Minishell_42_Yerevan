/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:10:31 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/03 11:41:01 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	get_pipe_syntax_err(t_src *data)
{
	t_tokens	*tmp;

	tmp = data->token_list;
	while (tmp)
	{
		if (tmp->type == 0)
		{
			if (tmp->next == NULL)
				return (1);
			else if (tmp->next->type == 0)
				return (2);
			else if (tmp->next->type == 8 && tmp->next->next->type == 0)
				return (3);
			else if (tmp->next->type == 8 && tmp->next->next == NULL )
				return (3);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	get_redir_syntax_err(t_src *data)
{
	t_tokens	*tmp;

	tmp = data->token_list;
	while (tmp)
	{
		if (tmp->type >= 1 && tmp->type <= 4)
		{
			if (tmp->next == NULL)
				return (1);
			else if (tmp->next->type >= 0 && tmp->next->type <= 4)
				return (2);
			else if (tmp->next->type == 8
				&& (tmp->next->type >= 0 && tmp->next->type <= 4))
				return (3);
			else if (tmp->next->type == 8 && tmp->next->next == NULL )
				return (4);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	add_sintex_error(t_src *data)
{
	t_tokens	*tmp;

	tokens_list_start(data);
	if (get_pipe_syntax_err(data) != 0)
		printf(" syntax error near unexpected token `|'\n"); // grel exit funkcia
	if (get_redir_syntax_err(data) != 0)
		printf(" syntax error near unexpected token `<>'\n"); // grel exit funkcia || bolor depqeri hamar > , >>,>>>,>>>>,<,<<,<<<,<<<<,<>,<>>,<<>>, ev ayln
	tmp = NULL;
	// print_tokens(data); // verjum jnji funkcian
}

// 
//2) mini$ <<     newline
//3)