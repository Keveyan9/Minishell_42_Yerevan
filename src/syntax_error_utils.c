/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:50:29 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/26 22:40:26 by artadevo         ###   ########.fr       */
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
	printf("{{%d}}\n",data->syntax_err);
	if (data->syntax_err > 0 && data->syntax_err < 127)
		printf("++syntax error near unexpected token `%c\"\n", (char)(data->syntax_err));
	else
		printf("syntax error near unexpected token `%s\"\n", "newline");
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
