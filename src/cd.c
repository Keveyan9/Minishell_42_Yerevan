/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:52:54 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 15:52:58 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	cd_half(t_src *data)
{
	t_env		*oldpwd;
	t_env		*pwd;
	static int	pwd_flag;

	oldpwd = find_env(data->env, "OLDPWD");
	pwd = find_env(data->env, "PWD");
	if (oldpwd)
	{
		write(1,"test\n",5);
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
		write(1,"test2\n",6);
		pwd_flag = 1;
		new_node(data);
		data->env->key = ft_strdup("OLDPWD");
		data->env->value = pwd->value;
		data->env->flag_p = 0;
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
		cd_half(data);
	else if (data->cl_in->word[1])
	{
		error_string = ft_strjoin("minishell: cd: ", data->cl_in->word[1]);
		perror(error_string);
		free(error_string);
	}
}
