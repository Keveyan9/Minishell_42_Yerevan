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

static void give_place(t_src *data)
{
	t_env *chek_place;
	t_env *grup;
	size_t len;
	int len2;
	int campeyer;

	campeyer = 0;
	chek_place = data->env;
	while (chek_place)
	{
		chek_place->place = 0;
		len = ft_strlen(chek_place->key);
		len2 = len;
		grup = data->env;
		while (grup->next)
		{
			if (len < ft_strlen(grup->key))
				len = ft_strlen(grup->key);
			campeyer = ft_strncmp(chek_place->key, grup->key, len);
			if (campeyer >= 0)
				chek_place->place++;
			len = len2;
			grup = grup->next;
		}
		chek_place->flag_p = 0;
		chek_place = chek_place->next;
	}
}

void print_export(t_src *data)
{
	// int go_on;
	t_env *grup;
	int big;
	char c;

	c = '"';
	big = 0;
	// go_on = 1 ;
	give_place(data);
	grup = data->env;
	while (grup->next)
	{
		if (big < grup->place)
			big = grup->place;
		grup = grup->next;
	}
	grup = data->env;
	// while (big >= 0)
	// {
	 	grup = data->env;
		while (grup)
		{
			// if (big >= grup->place && grup->flag_p == 0)
			// {
				printf("__%d__%s=%c%s%c\n", grup->place, grup->key, c, grup->value, c);
				grup->flag_p = 1;
			// 	big--;
			// }
			grup = grup->next;
		//need chanj this moments
	}
	//}
}
