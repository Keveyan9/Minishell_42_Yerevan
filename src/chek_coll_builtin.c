/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_coll_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:57:31 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 15:57:34 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	chek_coll(t_src *data)
{
	if (ft_strlen(data->cl_in->word[0]) == 4
		&& ft_strncmp(data->cl_in->word[0], "echo", 4) == 0)
		echo(data);
	else if (ft_strlen(data->cl_in->word[0]) == 2
		&& ft_strncmp(data->cl_in->word[0], "cd", 2) == 0)
		cd(data);
	else if (ft_strlen(data->cl_in->word[0]) == 3
		&& ft_strncmp(data->cl_in->word[0], "pwd", 3) == 0)
		pwd(data);
	else if (ft_strlen(data->cl_in->word[0]) == 6
		&& ft_strncmp(data->cl_in->word[0], "export", 6) == 0)
		export(data);
	else if (ft_strlen(data->cl_in->word[0]) == 5
		&& ft_strncmp(data->cl_in->word[0], "unset", 5) == 0)
		unset(data);
	else if (ft_strlen(data->cl_in->word[0]) == 3
		&& ft_strncmp(data->cl_in->word[0], "env", 3) == 0)
		env_f(data);
	else if (ft_strlen(data->cl_in->word[0]) == 4
		&& ft_strncmp(data->cl_in->word[0], "exit", 4) == 0)
		exit_f(data);
	return (1);
}

int	chek_coll_builtin(t_src *data)
{
	if (data->cl_in && data->cl_in->word)
	{
		if (chek_coll(data))
			return (1);
	}
	return (0);
}
