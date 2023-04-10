/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 00:25:07 by artadevo          #+#    #+#             */
/*   Updated: 2023/04/11 01:48:19 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_export(t_src *data)
{
	t_env	*tmp;
	int		c;

	c = 'A';
	tmp = data->env;
	while (c <= 'Z')
	{
		while (tmp)
		{
			if (tmp->key[0] == (char)c || tmp->key[0] == (char)(c + 32))
			{
				printf("declare -x %s", tmp->key);
				if (tmp->flag_p == 0)
					printf("=");
				if (tmp->value)
					printf("%s", tmp->value);
				printf("\n");
			}
		tmp = tmp->next;
		}
		tmp = data->env;
		c++;
	}
}
