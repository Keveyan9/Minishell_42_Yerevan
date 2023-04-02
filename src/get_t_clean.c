/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:37:38 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/02 15:37:52 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	join_for_oll(t_src *data)
{
	char	*boxs;

	boxs = NULL;
	if (data->token_list->type < 5 && data->token_list->next->type == 8)
		data->token_list = data->token_list->next;
	if (data->token_list->type == 6 || data->token_list->type == 7 )
	{
		boxs = ft_strdup(data->cl_in->oll);
		free(data->cl_in->oll);
		data->cl_in->oll = NULL;
		data->cl_in->oll = ft_strjoin(boxs, "'");
		free(boxs);
	}
	boxs = ft_strdup(data->cl_in->oll);
	free(data->cl_in->oll);
	data->cl_in->oll = ft_strjoin(boxs, data->token_list->token);
	free(boxs);
	boxs = NULL;
}

static void	join_token_for_clean(t_src *data)
{
	char	*boxs;
	char	*for_word;

	boxs = NULL;
	for_word = NULL;
	while (data->token_list && data->token_list->type != 0)
	{
		join_for_oll(data);
		if(!(data->token_list->type > 0 && data->token_list->type < 5)
				&& ((data->token_list->prev && data->token_list->prev->type > 4 ) 
					|| !data->token_list->prev))
		{
			boxs = ft_strdup(for_word);
			free(for_word);
			for_word = NULL;
			if(data->token_list->token[0] == '$' && data->token_list->token[1])
				dolar_change(data->env,&data->token_list->token,1);
			for_word = ft_strjoin(boxs, data->token_list->token);
			free(boxs);
			boxs = NULL;
		}
		data->token_list = data->token_list->next;
	}
	if (for_word)
	{
		data->cl_in->word = ft_split(for_word, ' ');
		free(for_word);
		for_word = NULL;
	}
}

static t_cl_in	*new_node_t_cl_in ()
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

static void cneqt_clin_nod (t_src *data, t_cl_in *nod)
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
// sintex orori pahe jshtem


void	get_t_cl_in_list(t_src *data)
{	
	t_cl_in	*nod;

	tokens_list_start(data);
	data->tokens_head = data->token_list;
	nod = new_node_t_cl_in();
	if (!nod)
		return;
	cneqt_clin_nod(data, nod);
	while (data->token_list)
	{
		join_token_for_clean(data);
		if (data->token_list && (data->token_list->type == 0 || data->token_list->next == NULL))
		{
			nod = new_node_t_cl_in();
			if(!nod)
				return;
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

	int i = -1;
	tmp = data->cl_in;
	while (tmp && tmp->prev != NULL)
	{
		tmp = tmp->prev;
	}
	while (tmp)
	{
		i = -1;
		while(tmp->word && tmp->word[++i])
			printf("word%d = [%s] \n",i, tmp->word[i]);
		// i = -1;
		// while(tmp->heredoc && tmp->heredoc[++i])
		// 	printf("heredoc%d = [%s] \n",i, tmp->heredoc[i]);
		printf("oll = [%s]\n", tmp->oll);
		tmp = tmp->next;
	}
}