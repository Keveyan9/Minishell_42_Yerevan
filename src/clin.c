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

// static void *now_nod_clin()
// {
// 	t_cl_in *nod ;

// 	nod =  malloc(sizeof(t_cl_in));
// 	if (!nod)
// 		return(NULL);
// 	//nod->fd = 0;
// 	nod->id = NULL;
// 	nod->next = NULL;
// 	nod->oll = NULL;
// 	nod->prev = NULL;
// 	nod->word = NULL;
// 	return(nod);
// }
// static void cneqt_clin_nod(t_src *data, t_cl_in *nod)
// {
// 	if(data->clin_head == NULL)
// 	{
// 		data->clin_head = nod;
// 		data->clin_last = nod;
// 		data->cl_in = nod;
// 	}
// 	else
// 	{
// 		nod->prev = data->clin_last;
// 		data->clin_last->next = nod;
// 		data->clin_last = nod;
// 	}
	
// }

// void	clin(t_src *data)
// {
// 	int n;

// 	n = data->pipes_count + 1;
// 	t_cl_in *nod;

// 	while(n--)
// 	{
// 		nod = now_nod_clin();
// 		if(!nod)
// 			return;
// 		nod->id = ft_strdup("ls");
// 		nod->word = ft_split(nod->id,' ');
// 		nod->oll = ft_strdup("ls");
// 		cneqt_clin_nod(data,nod);
// 	}
// }
