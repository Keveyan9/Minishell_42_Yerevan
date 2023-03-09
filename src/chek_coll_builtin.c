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
	//printf("%d\n",ft_strncmp(data->cl_in->id, "pwd",));
	if (ft_strlen(data->cl_in->id) == 4 && ft_strncmp(data->cl_in->id, "echo", 4) == 0)
		echo(data);
	else if ( ft_strlen(data->cl_in->id) == 2 && ft_strncmp(data->cl_in->id, "cd", 2) == 0)
		cd(data);
	else if (ft_strlen(data->cl_in->id) == 3 && ft_strncmp(data->cl_in->id, "pwd", 3) == 0)
		pwd();
	else if (ft_strlen(data->cl_in->id) == 6 && ft_strncmp(data->cl_in->id, "export",6) == 0 )
		export(data);
	else if (ft_strlen(data->cl_in->id) == 5 && ft_strncmp(data->cl_in->id, "unset", 5) == 0 )
		unset(data);
	else if (ft_strlen(data->cl_in->id) == 3 && ft_strncmp(data->cl_in->id, "env", 3) == 0 )
		env_f(data);
	else if (ft_strlen(data->cl_in->id) == 4 && ft_strncmp(data->cl_in->id, "exit", 4) == 0)
		printf("#############exit############\n");
	else
		return (1);
	 return (0);
}
