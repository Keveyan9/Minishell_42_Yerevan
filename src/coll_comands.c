/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coll_comands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:06:41 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 16:06:44 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

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

	comand_path = find_comand_path(data);
	env = list_to_array(data);
	data->error = execve(comand_path, data->cl_in->word, env);
	frik(env);
	free(comand_path);
	if (data->error != 0)
		perror("execve");
}

	/// stex karoxa petq e exit avelcanel vor ete execve
	// chashxati free ani durs ga
	// bayc ed en depqum erb inqe chayldi mej e
