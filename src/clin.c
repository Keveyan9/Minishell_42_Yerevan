/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:05:27 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 16:05:29 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clin(t_src *data)
{
	data->cl_in = malloc(sizeof(t_cl_in));
	data->cl_in->prev = NULL;
	data->cl_in->id = ft_strdup("ls");
	data->cl_in->word = ft_split("ls -la",' ');
	data->cl_in->oll = ft_strdup("ls -la ");
	data->cl_in->next = malloc(sizeof(t_cl_in) );
	data->cl_in->next->prev=data->cl_in;
	data->cl_in=data->cl_in->next;
	data->cl_in->id = ft_strdup("grep");
	data->cl_in->word = ft_split("grep l",' ');
	data->cl_in->oll = ft_strdup("grep l");
	data->cl_in->next = malloc(sizeof(t_cl_in));
	data->cl_in->next->prev =data->cl_in;
	data->cl_in =data->cl_in->next;
	data->cl_in->id = ft_strdup("wc");
	data->cl_in->word = ft_split("wc -l",' ');
	data->cl_in->oll = ft_strdup("wc -l");
	data->cl_in->next = NULL;
	data->cl_in = data->cl_in->prev->prev;
    // printf("test %s;",data->cl_in->id);
    //     printf("test %s;",data->cl_in->next->id);
    //          printf("test %s;",data->cl_in->next->next->id);
}
