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

static char **list_to_array(t_src *data)
{
	t_coll_comand var;

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

void coll_comands(t_src *data)
{
	char *comand_path;
	char **env;
	char **name_argument;
	env = list_to_array(data);

	comand_path = ft_strjoin(data->home_path, &(data->cl_in->id[1]));
	name_argument = (char **)malloc(sizeof(char *) * 3);
	name_argument[0] = ft_strdup(data->cl_in->id);
	name_argument[1] = ft_strdup("1");
	name_argument[2] = NULL;
	data->error = execve(comand_path, name_argument, env);
	free(comand_path);
	frik(name_argument);
	comand_path = find_comand_path(data);
	if (comand_path)
		data->error = execve(comand_path, data->cl_in->word, env);
	frik(env);
	free(comand_path);
	oll_free(data);
	if (data->error != 0)
		perror("execve_");
	exit(data->error);
}

/// stex karoxa petq e exit avelcanel vor ete execve
// chashxati free ani durs ga
// bayc ed en depqum erb inqe chayldi mej e
