/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:10:31 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/30 23:53:34 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	get_pipe_syntax_err(char tokin)
{
	if (tokin)
	{
		if (tokin == '|')
			return ('|');
		if (tokin == ';')
			return (';');
		if (tokin == ')')
			return (')');
	}
	return (0);
}

int	char_tokin1_norm(char *tokin, int *i)
{
	if (tokin && tokin[*i] && tokin[*i] == '|')
	{
		*i += 1;
		return (1);
	}
	if (tokin && tokin[*i] && tokin[*i] == '>'
		&& tokin[*i + 1] && tokin[*i + 1] == '>')
	{
		*i += 2;
		return (6);
	}
	return (0);
}

int	char_tokin1(char *tokin, int *i)
{
	int	l;

	l = char_tokin1_norm(tokin, i);
	if (l > 0)
		return (l);
	if (tokin && tokin[*i] && tokin[*i] == '<'
		&& tokin[*i + 1] && tokin[*i + 1] == '<')
	{
		*i += 2;
		return (7);
	}
	if (tokin && tokin[*i] && tokin[*i] == '<')
	{
		*i += 1;
		return (8);
	}
	if (tokin && tokin[*i] && tokin[*i] == '>')
	{
		*i += 1;
		return (5);
	}
	return (0);
}

int	get_redir_syntax_err(char *tokin, int *i)
{
	if (tokin && tokin[*i] && tokin[*i] == '>'
		&& tokin[*i + 1] && tokin[*i + 1] == '>')
	{
		*i += 2;
		return (150);
	}
	if (tokin && tokin[*i] && tokin[*i] == '<'
		&& tokin[*i + 1] && tokin[*i + 1] == '<')
	{
		*i += 2;
		return (150);
	}
	if (tokin && tokin[*i] && tokin[*i] == '<')
	{
		*i += 1;
		return (150);
	}
	if (tokin && tokin[*i] && tokin[*i] == '>')
	{
		*i += 1;
		return (150);
	}
	return (0);
}

void	add_sintex_error(t_src *data)
{
	t_tokens	*tmp;

	tmp = data->token_list;
	while (tmp && tmp->next != NULL)
	{
		if (tmp->type == 0)
			data->pipes_count += 1;
		tmp = tmp->next;
	}
	get_t_cl_in_list(data);
	// print_t_cl_in(data);
}

// 
//2) mini$ <<     newline
//3)bahe

// int	get_pipe_syntax_err(t_src *data)
// {
// 	t_tokens	*tmp;

// 	tmp = data->token_list;
// 	while (tmp)
// 	{
// 		if (tmp->type == 0)
// 		{
// 			if (tmp->next == NULL)
// 				tmp->syn_err = 124;
// 			else if (tmp->next->type == 0)
// 				tmp->syn_err = 124;
// 			else if (tmp->next->type == 8 && tmp->next->next->type == 0)
// 				tmp->syn_err = 124;
// 			else if (tmp->next->type == 8 && tmp->next->next == NULL )
// 				tmp->syn_err = 124;
// 		}
// 		if (tmp->syn_err > 0)
// 		{
// 			data->syntax_err = 124;
// 			return (1);
// 		}
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

// int	get_redir_syntax_err2(t_src *data)
// {
// 	t_tokens	*tmp;

// 	tmp = data->token_list;
// 	while (tmp)
// 	{
// 		if (tmp->type >= 1 && tmp->type <= 4)
// 		{
// 			if (tmp->next && tmp->next->type == 8)
// 				token_line_dell(tmp->next);
// 			if ((tmp->next && tmp->next->next) && (tmp->type == 1
// 					&& tmp->next->type == 1))
// 				return (registor_syn_err(data, tmp, 250));
// 			if ((tmp->next && tmp->next->next) && (tmp->type == 2
// 					&& tmp->next->type == 2 && (tmp->next->next->type == 2
// 						|| tmp->next->next->type == 4)))
// 				return (registor_syn_err(data, tmp, 350));
// 			if (tmp->next == NULL || (tmp->type == 2 && tmp->next->type == 4)
// 				|| (tmp->type == 4 && tmp->next->type == 3))
// 				return (registor_syn_err(data, tmp, 150));
// 			else if ((tmp->type == 1 || tmp->type == 2) && tmp->next->type == 3)
// 				return (registor_syn_err(data, tmp, 62));
// 			else if ((tmp->type == 2 && tmp->next->type == 2)
// 				|| ((tmp->type == 1 || tmp->type == 3) && tmp->next->type == 4))
// 				return (registor_syn_err(data, tmp, 60));

// 		}
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

// int	registor_syn_err(t_src *data, t_tokens *tmp, int syntax_err)
// {
// 	tmp->syn_err = syntax_err;
// 	data->syntax_err = syntax_err;
// 	return (syntax_err);
// }