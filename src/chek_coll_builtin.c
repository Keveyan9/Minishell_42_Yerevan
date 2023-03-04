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

int	chek_coll_builtin(t_src *data)
{
	int	len;

	len = ft_strlen(data->cl_in->id);
	if (!ft_strncmp(data->cl_in->id, "echo", len))
		echo(data);
	else if (!ft_strncmp(data->cl_in->id, "cd", len))
		cd(data);
	else if (!ft_strncmp(data->cl_in->id, "pwd", len))
		pwd();
	else if (!ft_strncmp(data->cl_in->id, "export", len))
		export(data);
	else if (!ft_strncmp(data->cl_in->id, "unset", len))
		unset(data);
	else if (!ft_strncmp(data->cl_in->id, "env", len))
		env_f(data);
	else if (!ft_strncmp(data->cl_in->id, "exit", len))
		printf("#############exit############\n");
	else
		return (1);
	return (0);
}
