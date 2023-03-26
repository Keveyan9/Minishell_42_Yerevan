/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:10:31 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/26 23:35:03 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	get_pipe_syntax_err(t_src *data)
{
	t_tokens	*tmp;

	tmp = data->token_list;
	while (tmp && (tmp->type == 0))
	{
		if (tmp->next == NULL)
			tmp->syn_err = 1;
		else if (tmp->next->type == 0)
			tmp->syn_err = 1;
		else if (tmp->next->type == 8 && tmp->next->next->type == 0)
			tmp->syn_err = 1;
		else if (tmp->next->type == 8 && tmp->next->next == NULL )
			tmp->syn_err = 1;
		if (tmp->syn_err != 0)
			return (1);
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
		if (tmp->next && tmp->next->type == 8)
			token_line_dell(tmp->next);
// printf("barev2\n");
		if (tmp->next == NULL || (tmp->type == 2 && tmp->next->type == 4)
			|| (tmp->type == 4 && tmp->next->type == 3))
			return (registor_syn_err(data, tmp, 150));
		else if ((tmp->type == 1 || tmp->type == 2) && tmp->next->type == 3)
			return (registor_syn_err(data, tmp, 62));
		else if ((tmp->type == 2 && tmp->next->type == 2)
			|| ((tmp->type == 1 || tmp->type == 3) && tmp->next->type == 4))
			return (registor_syn_err(data, tmp, 60));
		tmp = tmp->next;
	}
	return (0);
}
		// else if (tmp->next->type == 8
		// 	&& (tmp->next->type >= 0 && tmp->next->type <= 4))
		// 	return (3);
		// else if (tmp->next->type == 8 && tmp->next->next == NULL )
		// 	return (4);

int	registor_syn_err(t_src *data, t_tokens *tmp, int syntax_err)
{
	tmp->syn_err = syntax_err;
	data->syntax_err = syntax_err;
	return (syntax_err);
}

void	add_sintex_error(t_src *data)
{
	t_tokens	*tmp;
	tokens_list_start(data);
	if (get_pipe_syntax_err(data) != 0)
		;// printf(" syntax error near unexpected token `|--'\n"); // grel exit funkcia
// printf("barev3\n");
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
printf("barev1\n");
	get_t_cl_in_list(data);
printf("barev3\n");
	// print_tokens(data); // verjum jnji funkcian
}

// 
//2) mini$ <<     newline
//3)bahe