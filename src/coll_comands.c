/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coll_comands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:06:41 by skeveyan          #+#    #+#             */
/*   Updated: 2023/03/26 17:54:58 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	can_not_coll_comand(t_src *data)
{
	ft_putstr_fd(data->cl_in->word[0], 1);
	ft_putstr_fd("  : comand can not faund\n", 1);
	data->error = 127;
}

static char	**list_to_array(t_src *data)
{
	t_coll_comand	var;

	var.i = 0;
	var.origin = data->env;
	var.row = 0;
	while (var.origin)
	{
		var.origin = var.origin->next;
		var.row++;
	}
	var.env_aray = (char **)malloc(sizeof(char *) * (var.row + 1));
	if (!var.env_aray)
		return (NULL);
	var.origin = data->env;
	while (var.origin)
	{
		var.key_equal = ft_strjoin(var.origin->key, "=");
		var.env_aray[var.i++] = ft_strjoin(var.key_equal, var.origin->value);
		free(var.key_equal);
		var.origin = var.origin->next;
	}
	var.env_aray[var.i] = NULL;
	return (var.env_aray);
}

void	coll_comands(t_src *data)
{
	char	*comand_path;
	char	**env;
	int		n;

	n = 0;
	comand_path = NULL;
	env = list_to_array(data);
	while (data->cl_in->word[0][n] && data->cl_in->word[0][n] != '/'
		&& data->cl_in->word[0][n++] != '.' );
	if ((data->cl_in->word[0][n] == '/' || data->cl_in->word[0][n] == '.'))
	{
		if (!access(data->cl_in->word[0], F_OK))
			execve(data->cl_in->word[0], data->cl_in->word, env);
		perror(data->cl_in->word[0]);
	}
	else
	{
		comand_path = find_comand_path(data);
		execve(comand_path, data->cl_in->word, env);
		can_not_coll_comand(data);
		free_give_null(&comand_path);
	}
	frik(env);
	oll_free(data);
	exit(data->error);
}
