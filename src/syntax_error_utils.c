/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:50:29 by artadevo          #+#    #+#             */
/*   Updated: 2023/02/27 21:46:48 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	get_frst_element(char *s, t_src *data)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '|')
		{
			data->index_s_err = i;
			data->syntax_err = 124;
			return ;
		}
		else if (s[i] == ')')
		{
			data->index_s_err = i;
			data->syntax_err = 41;
			return ;
		}
		else if (s[i] == ';')
		{
			data->index_s_err = i;
			data->syntax_err = 59;
			return ;
		}
	}
}

void	print_eyntax_err(t_src *data)
{
	if (data->syntax_err >= 0 && data->syntax_err < 127)
		printf("mint$ syntax error near unexpected token `%c\"\n", (char)(data->syntax_err));
	else
		printf("mint$ syntax error near unexpected token `%s\"\n", "newline");
}
