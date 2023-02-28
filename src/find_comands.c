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

char	*find_comand_path(t_src *data)
{
	char	**oll_path;
	char	*comand_slesh;
	char	*path_chek;
	t_env	*env_list;
	int		n;

	path_chek = NULL;
	n = 0;
	env_list = find_env(data->env, "PATH");
	if (!env_list)
	{
		printf("%s: No such file or directory \n", data->cl_in->id);
		return (NULL);
	}
	comand_slesh = ft_strjoin("/", data->cl_in->id);
	oll_path = ft_split(env_list->value, ':');
	while (oll_path[n])
	{
		if (path_chek)
			free(path_chek);
		path_chek = ft_strjoin(oll_path[n++], comand_slesh);
		if (!access(path_chek, F_OK))
		{
			free(comand_slesh);
			frik(oll_path);
			return (path_chek);
		}
	}
	free(comand_slesh);
	frik(oll_path);
	if (path_chek)
		free(path_chek);
	return (NULL);
}
