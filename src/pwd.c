/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:45:00 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 16:45:14 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	pwd(t_src *data)
{
	char	*v_pwd;

	v_pwd = getcwd(NULL,0);
	if(!v_pwd)
	{
		perror("pwd error");
		data->error = 1;
	}
	else
	{
		printf("%s\n",v_pwd);
		data->error = 0;
		free(v_pwd);
		v_pwd = NULL;
	}
}
