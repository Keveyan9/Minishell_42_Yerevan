/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:33:21 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/06 00:07:10 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static void	not_valid_argument(t_src *data, t_export *var)
{
	char	*not_valid_arg;

	not_valid_arg = NULL;
	not_valid_arg = ft_strjoin("is not valid argument name  ",
			data->cl_in->word[var->row]);
	write(1, not_valid_arg, ft_strlen(not_valid_arg));
	write(1, "\n", 1);
	free(not_valid_arg);
	not_valid_arg = NULL;
	data->error = 1;
}

static int	valid_argument(t_src *data, t_export *var)
{
	var->i = find_index(data->cl_in->word[var->row], '=');
	var->string_len = ft_strlen(data->cl_in->word[var->row]);
	if (campeyr(data, var))
	{
		data->error = 1;
		var->add = 0;
		return (1);
	}
	else
		data->error = 0;
	var->add = 0;
	return (0);
}

void	export(t_src *data)
{
	t_export	var;

	var.value = NULL;
	var.key = NULL;
	var.add = 0;
	var.row = 1;
	if (data->cl_in->word[1])
	{
		while (data->cl_in->word[var.row])
		{
			var.i = 0;
			var.string_len = 0;
			if (ft_isalpha(data->cl_in->word[var.row][0])
				|| data->cl_in->word[var.row][0] == '_'
				|| data->cl_in->word[var.row][0] == '\'')
				valid_argument (data, &var);
			else
				not_valid_argument(data, &var);
			var.row++;
		}
	}
	else
		print_export(data);
}
