/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:52:54 by skeveyan          #+#    #+#             */
/*   Updated: 2023/03/26 17:24:32 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cd_half(t_src *data)
{
	t_env		*oldpwd;
	t_env		*pwd;
	static int	pwd_flag;
	t_env		*newnode;

	oldpwd = find_env(data->env, "OLDPWD");
	pwd = find_env(data->env, "PWD");
	if (oldpwd)
	{
		pwd_flag = 1;
		free(oldpwd->value);
		oldpwd->value = NULL;
		if (pwd)
			oldpwd->value = pwd->value;
		else
			oldpwd = NULL;
	}
	else if (!pwd_flag && pwd)
	{
		pwd_flag = 1;
		newnode = new_node();
		newnode->key = ft_strdup("OLDPWD");
		newnode->value = pwd->value;
		put_env_node(data, newnode);
	}
	if (pwd)
		pwd->value = getcwd(NULL, 0);
}

void	cd(t_src *data)
{
	char	*error_string;
	if (data->cl_in->word[2])
	{
		printf("cd : too many arguments");
		data->error = 1;
		return ;
	}
	data->error = chdir(data->cl_in->word[1]);
	if (data->error == 0)
	{
		cd_half(data);
		data->error = errno;
	}
	else if (data->cl_in->word[1])
	{
		error_string = ft_strjoin("minishell: cd: ", data->cl_in->word[1]);
		data->error = 1;
		perror(error_string);
		free(error_string);
		error_string = NULL;
	}
}
