/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:43:02 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 16:43:18 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	print_export(t_src *data)
{
	t_env	*chek_place;
	t_env	*origin;
	int		chek_flag;
	char 	c;

	c = '"';
	chek_flag = 1;
	origin = data->env;
	chek_place = origin;

	// while (chek_flag)
	// {
	// 	chek_place = origin;
	// 	chek_flag = 0;
	// 	while(chek_place)
	// 	{
	// 		if(grup->flag_p == 0) 
	// 		{
	// 			chek_flag = 1;
	// 			grup->flag_p = 1;
	// 			printf("%s=%c%s%c\n", grup->key, c, grup->value, c)
	// 		}
	// 		chek_place = chek_place->next;
	// 	}
	// }
}
