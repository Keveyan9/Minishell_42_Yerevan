/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t_cl_in_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:35:47 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/25 15:33:43 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	free_token(t_src *data)
{
	while (data->token_list && data->token_list->prev)
		data->token_list = data->token_list->prev;
	while (data->token_list)
	{
		if (data->token_list->token)
			free(data->token_list->token);
		if (data->token_list->next)
		{
			data->token_list = data->token_list->next;
			free(data->token_list->prev);
		}
		else
		{
			free(data->token_list);
			break ;
		}
	}
}

char	*get_t_cl_in_list_heredoc(t_src *data, char *str1, char **str)
{
	// char	*str1;

	//str1 = NULL;
	str1 = ft_strjoin(str1, data->token_list->token);
	if (data->token_list->next->type == 8)
		token_line_dell(data->token_list->next);
	data->token_list = data->token_list->next;
	(*str) = ft_strjoin((*str), data->token_list->token);
	str1 = ft_strjoin(str1, data->token_list->token);
	str1 = ft_strjoin(str1, " ");
	return (str1);
}

void	get_t_cl_in_list(t_src *data)
{
	char	*str;
	char	*str1;
	char	*str2;

	str = NULL;
	str1 = NULL;
	str2 = NULL;
	tokens_list_start(data);
	while (data->token_list)
	{
		if (data->token_list->type != 0)
		{
			str = ft_strjoin(str, data->token_list->token);
			if (data->token_list->type > 0 && data->token_list->type < 5)
				str1 = get_t_cl_in_list_heredoc(data, str1, &str);
			else
				str2 = ft_strjoin(str2, data->token_list->token);
		}
		if (data->token_list->type == 0 || data->token_list->next == NULL)
		{
			data->cl_in = new_node_t_cl_in(str, str1, str2, data->cl_in);
			free(str);
			free(str1);
			free(str2);
			str = NULL;
			str1 = NULL;
			str2 = NULL;
		}
		data->token_list = data->token_list->next;
	}
	free_token(data);
	print_t_cl_in(data);
}

t_cl_in	*new_node_t_cl_in(char *str, char *str1, char *str2, t_cl_in *cl_in)
{
	t_cl_in	*node;

	node = (t_cl_in *)malloc(sizeof(t_cl_in));
	if (!node)
		return (0);
	node->oll = ft_strdup(str);
	node->word = ft_split(str2, ' ');
	node->heredoc = ft_split(str1, ' ');
	if (node->word[0])
		node->id = ft_strdup(node->word[0]);
	else
		node->id = NULL;
	node->in_fd = -2;
	node->out_fd = -2 ;
	node->next = NULL;
	node->prev = cl_in;
	if (cl_in)
		cl_in->next = node;
	return (node);
}

//------verjum jnji --------
//-----VVVVVVVVVVVVV--------

void	print_t_cl_in(t_src *data)
{
	t_cl_in	*tmp;
	int i = -1;

	tmp = data->cl_in;
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
	}
	while (tmp)
	{
		printf("id = [%s]\n", tmp->id);
		i = -1;
		while(tmp->word[++i])
			printf("word%d = [%s] \n",i, tmp->word[i]);
		i = -1;
		while(tmp->heredoc[++i])
			printf("heredoc%d = [%s] \n",i, tmp->heredoc[i]);
		printf("oll = [%s]\n", tmp->oll);
		tmp = tmp->next;
	}
}
