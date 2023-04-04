/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_comands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:36:38 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 16:36:51 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static char	*find_path( char *comand_slesh, char **oll_path)
{
	char	*path_chek;
	int		n;

	path_chek = NULL;
	n = 0;
	while (oll_path[n])
	{
		if (path_chek)
			free(path_chek);
		path_chek = ft_strjoin(oll_path[n], comand_slesh);
		if (!access(path_chek, F_OK))
			return (path_chek);
		n++;
	}
	if (path_chek)
		free(path_chek);
	return (NULL);
}

char	*find_comand_path(t_src *data)
{
	char	**oll_path;
	char	*comand_slesh;
	char	*path_chek;
	t_env	*env_list;

	path_chek = NULL;
	env_list = find_env(data->env, "PATH");
	if (!env_list)
	{
		printf("%s: No such file or directory \n", data->cl_in->word[0]);
		return (NULL);
	}
	comand_slesh = ft_strjoin("/", data->cl_in->word[0]);
	oll_path = ft_split(env_list->value, ':');
	path_chek = find_path (comand_slesh, oll_path);
	free(comand_slesh);
	frik(oll_path);
	if (path_chek)
		return (path_chek);
	return (NULL);
}
