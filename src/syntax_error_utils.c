/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:50:29 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/27 01:35:05 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	get_frst_element(t_src *data)
{
	data->index_s_err = 0;
	data->syntax_err = 124;
	return ;
}

void	print_syntax_err(t_src *data)
{
	if (data->syntax_err > 0 && data->syntax_err < 127)
	{
		ft_putstr_fd("syntax error near unexpected token `", 2);
		ft_putchar_fd((char)(data->syntax_err), 2);
		ft_putstr_fd("\"\n", 2);
	}
	else if (data->syntax_err == 250)
		ft_putstr_fd("syntax error near unexpected token `>>\"\n", 2);
	else if (data->syntax_err == 350)
		ft_putstr_fd("syntax error near unexpected token `<<\"\n", 2);
	else
		ft_putstr_fd("syntax error near unexpected token `newline\"\n", 2);
}

void	get_short_line(t_src *data)
{
	char	*tmp;

	tmp = NULL;
	if (data->line)
	{
		tmp = ft_substr(data->line, 0, data->index_s_err);
		free(data->line);
		data->line = tmp;
		tmp = NULL;
	}
}
