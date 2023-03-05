/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t_cl_in_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:35:47 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/05 15:00:48 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	get_t_cl_in_list(t_src *data)
{
	char	*str;

	str = NULL;
	tokens_list_start(data);
	while (data->token_list)
	{
		if (data->token_list->type != 0)
			str = ft_strjoin(str, data->token_list->token);
		if (data->token_list->type == 0 || data->token_list->next == NULL)
		{
			data->cl_in = new_node_t_cl_in(str, data->cl_in);
			free(str);
			str = NULL;
		}
		data->token_list = data->token_list->next;
	}
	print_t_cl_in(data);
}

t_cl_in	*new_node_t_cl_in(char *str, t_cl_in *cl_in)
{
	t_cl_in	*node;
	int		i;

	i = 0;
	node = (t_cl_in *)malloc(sizeof(t_cl_in));
	if (!node)
		return (0);
	node->oll = str;
	node->word = ft_split(str, ' ');
	node->id = node->word[0];
	node->next = NULL;
	node->prev = cl_in;
	if (cl_in)
		cl_in->next = node;
	return (node);
}

//------verjum jnji --------
//-----VVVVVVVVVVVVV--------

void		print_t_cl_in(t_src *data)
{
	t_cl_in	*tmp;

	tmp = data->cl_in;
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
	}
	while (tmp)
	{
		printf("id = [%s]\noll = [%s]\n", tmp->id, tmp->oll);
		tmp = tmp->next;
	}
}
