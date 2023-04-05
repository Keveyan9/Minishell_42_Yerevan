/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_out_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:18:41 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/03 14:18:43 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static void	open_file_new_write(t_src *data, int *row)
{
	int		len;
	char	*name;

	len = find_plase(&(data->cl_in->oll[*row]), ' ');
	name = ft_substr(data->cl_in->oll,*row, len);
	data->cl_in->pip_her_doc[1] = open (name, O_RDWR
			| O_CREAT | O_TRUNC, 0644);
	data->error = errno;
	(*row) = (*row) + len ;
	free(name);
	name = NULL;
}

void	chek_out_file(t_src *data, int *row)
{
	char	*name;
	int		len;

	if (data->cl_in->pip_her_doc[1] > 0)
		close(data->cl_in->pip_her_doc[1]);
	if (data->cl_in->oll[*row] == '>')
	{
		(*row)++;
		if (data->cl_in->oll[*row] == ' ')
			(*row)++;
		len = find_plase(&(data->cl_in->oll[*row]), ' ');
		name = ft_substr(data->cl_in->oll,*row, len);
		data->cl_in->pip_her_doc[1] = open (name, O_RDWR
				| O_CREAT | O_APPEND, 0644);
		data->error = errno;
		(*row) = (*row) + len;
		free(name);
		name = NULL;
	}
	else
		open_file_new_write(data, row);
}
