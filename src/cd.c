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

static void	cd_mistake(t_src *data)
{
	char	*error_string;

	error_string = ft_strjoin("minishell: cd: ", data->cl_in->word[1]);
	data->error = 1;
	perror(error_string);
	free(error_string);
	error_string = NULL;
}

static void	creat_pwd(t_src *data, t_env *pwd)
{
	t_env	*newnode;

	newnode = new_node();
	newnode->key = ft_strdup("OLDPWD");
	newnode->value = pwd->value;
	put_env_node(data, newnode);
}

static void	cd_half(t_src *data)
{
	t_env		*oldpwd;
	t_env		*pwd;
	static int	pwd_flag = 0;

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
		creat_pwd(data, pwd);
		pwd_flag = 1;
	}
	if (pwd)
		pwd->value = getcwd(NULL, 0);
}

void	cd(t_src *data)
{
	if (data->cl_in->word[2])
	{
		printf("cd : too many arguments");
		data->error = 1;
		g_flags = 1;
		return ;
	}
	if (data->cl_in->word[1])
	{
		data->error = chdir(data->cl_in->word[1]);
		if (!g_flags)
		{
			cd_half(data);
			data->error = errno;
		}
		else if (data->cl_in->word[1])
			cd_mistake(data);
	}
}
