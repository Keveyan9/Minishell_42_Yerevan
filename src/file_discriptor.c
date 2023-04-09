/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_discriptor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:31:35 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/02 15:31:48 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cheak_old_fd(t_src *data, int *fd, int *n)
{
	while (data->cl_in->oll[*n] && data->cl_in->oll[*n] != '<' )
		(*n)++;
	if (data->cl_in->oll[*n] == '\0')
	{
		if (data->cl_in->pip_her_doc[0] > 0)
			close(data->cl_in->pip_her_doc[0]);
		data->cl_in->pip_her_doc[0] = *fd;
	}
	else
	{
		close(*fd);
		*fd = 0;
	}
}

static void	chek_in_file(t_src *data, int *row)
{
	char	*name;
	int		len;
	int		fd;
	int		n;

	fd = 0;
	len = *row;
	n = *row;
	len = find_plase (&(data->cl_in->oll[*row]), ' ');
	name = ft_substr(data->cl_in->oll, *row, len);
	fd = open (name, O_RDONLY, 0644);
	(*row) = (*row) + len - 1;
	if (fd == -1)
	{
		ft_putstr_fd(name, 1);
		ft_putstr_fd(" : No such file or directory\n", 1);
		data->error = 1;
		g_flags = 1;
		return ;
	}
	cheak_old_fd(data, &fd, &n);
	free(name);
	name = NULL;
}

static void	coll_chek_in_file(t_src *data, int *row)
{
	data->error = 0;
	if (*row == 0 || (*row > 0 && (data->cl_in->oll[(*row) - 1] != '<')))
	{
		(*row)++;
		if (data->cl_in->oll[*row] == ' ')
			(*row)++;
		chek_in_file(data, row);
	}
}

void	file_discriptor(t_src *data)
{
	int	row;

	row = -1;
	while (data->cl_in->oll[++row] && !g_flags)
	{
		if (data->cl_in->oll[row] == 39)
		{
			row++;
			while (data->cl_in->oll[row] != 39)
				row++;
		}
		if (data->cl_in->oll[row] == '>')
		{
			data->error = 0;
			row++;
			if (data->cl_in->oll[row] == ' ')
				row++;
			chek_out_file(data, &row);
			if (data->error != 0)
				g_flags = 1;
		}
		else if (data->cl_in->oll[row] == '<'
			&& (data->cl_in->oll[row + 1] != '<'))
			coll_chek_in_file(data, &row);
	}
}
