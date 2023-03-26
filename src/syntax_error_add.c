/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:10:31 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/26 15:46:14 by artadevo         ###   ########.fr       */
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
	while (tmp && (tmp->type >= 1 && tmp->type <= 4))
	{
		if ((tmp->type >= 1 && tmp->type <= 4) && tmp->next == NULL)
			return (registor_syn_err(data, 150));
		else if (tmp->next->type >= 0 && tmp->next->type <= 4)
			return (2);
		else if (tmp->next->type == 8
			&& (tmp->next->type >= 0 && tmp->next->type <= 4))
			return (3);
		else if (tmp->next->type == 8 && tmp->next->next == NULL )
			return (4);
		tmp = tmp->next;
	}
	return (0);
}

int	registor_syn_err(t_src *data, int syntax_err)
{
	data->token_list->syn_err = syntax_err;
	data->syntax_err = syntax_err;
	return (syntax_err);
}

void	add_sintex_error(t_src *data)
{
	t_tokens	*tmp;

	tokens_list_start(data);
	if (get_pipe_syntax_err(data) != 0)
		printf(" syntax error near unexpected token `|'\n"); // grel exit funkcia
	if (get_redir_syntax_err(data) != 0)
		printf(" syntax error near unexpected token `<>'\n"); // grel exit funkcia || bolor depqeri hamar > , >>,>>>,>>>>,<,<<,<<<,<<<<,<>,<>>,<<>>, ev ayln
	tokens_list_start(data);
	tmp = data->token_list;
	while (tmp && tmp->next != NULL)
	{
		if (tmp->type == 0)
			data->pipes_count += 1;
		tmp = tmp->next;
	}
	get_t_cl_in_list(data);
	// print_tokens(data); // verjum jnji funkcian
}

// 
//2) mini$ <<     newline
//3)bahe