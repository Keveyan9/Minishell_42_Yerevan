/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:37:38 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/05 23:57:49 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static t_cl_in	*new_node_t_cl_in(void)
{
	t_cl_in	*node;

	node = (t_cl_in *)malloc(sizeof(t_cl_in));
	if (!node)
		return (0);
	node->oll = NULL;
	node->word = NULL;
	node->pip_her_doc[0] = -2;
	node->pip_her_doc[1] = -2 ;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static void	cneqt_clin_nod(t_src *data, t_cl_in *nod)
{
	if (data->clin_head == NULL)
	{
		data->clin_head = nod;
		data->clin_last = nod;
		data->cl_in = nod;
	}
	else
	{
		nod->prev = data->clin_last;
		data->clin_last->next = nod;
		data->clin_last = nod;
		data->cl_in = nod;
	}
}

void	get_t_cl_in_list(t_src *data)
{	
	t_cl_in	*nod;

	tokens_list_start(data);
	data->tokens_head = data->token_list;
	nod = new_node_t_cl_in();
	if (!nod)
		return ;
	cneqt_clin_nod(data, nod);
	while (data->token_list)
	{
		join_token_for_clean(data);
		if (data->token_list && (data->token_list->type == 0
				|| data->token_list->next == NULL))
		{
			data->pipes_count++;
			nod = new_node_t_cl_in();
			if (!nod)
				return ;
			cneqt_clin_nod(data, nod);
		}
		if (data->token_list)
			data->token_list = data->token_list->next;
	}
	data->cl_in = data->clin_head;
}

void	print_t_cl_in(t_src *data)
{
	t_cl_in	*tmp;
	int		i;
	int		n;

	i = -1;
	n = 1;
	tmp = data->cl_in;
	while (tmp && tmp->prev != NULL)
	{
		tmp = tmp->prev;
	}
	while (tmp)
	{
		i = -1;
		while (tmp->word && tmp->word[++i])
			printf("word%d = [%s] \n", i, tmp->word[i]);
		if(tmp->oll)
			printf("oll = [%s]__%d\n\n", tmp->oll, n++);
		tmp = tmp->next;
	}
}
