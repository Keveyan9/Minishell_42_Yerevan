/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:30:42 by artadevo          #+#    #+#             */
/*   Updated: 2023/01/21 20:02:31 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_frst_bite(char c, char *s)
{
	int		i;
	char	t[2];

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			t[0] = c;
			t[1] = '\0';
			error_print(" syntax error near unexpected token `", t);
			return (128);
		}
		i++;
	}
	return (0);
}

t_src	*find_syntax_error(t_src *data)
{
	char	*str;
	int		i;

	i = -1;
	str = line_corector(data->line);
	if (check_frst_bite(str[0], "|;)"))
		data->syntax_err = 256;
	// else if ()
	return (data);
}
