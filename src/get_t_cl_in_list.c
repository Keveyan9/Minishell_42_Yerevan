/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t_cl_in_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:35:47 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/27 22:12:54 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// static void	free_token(t_src *data)
// {
// 	while (data->token_list && data->token_list->prev)
// 		data->token_list = data->token_list->prev;
// 	while (data->token_list)
// 	{
// 		if (data->token_list->token)
// 			free(data->token_list->token);
// 		if (data->token_list->next)
// 		{
// 			data->token_list = data->token_list->next;
// 			free(data->token_list->prev);
// 		}
// 		else
// 		{
// 			free(data->token_list);
// 			break ;
// 		}
// 	}
// }

char	*get_t_cl_in_list_heredoc(t_src *data, char *str1, char **str)
{
	char *s1;

	s1 = ft_strjoin(str1, data->token_list->token);
	free(str1);
	str1 = s1;
	if (data->token_list->next->type == 8)
		token_line_dell(data->token_list->next);
	data->token_list = data->token_list->next;
	s1 = ft_strjoin((*str), data->token_list->token);
	free(*str);
	*str = s1;
	s1 = ft_strjoin(str1, data->token_list->token);
	free(str1);
	str1 = s1;
	s1 = ft_strjoin(str1, " ");
	free(str1);
	str1 = s1;
	return (str1);
}

void	func_norm_get_t_cl_in_list(char **str, char **str1, char **str2)
{
	free(*str);
	free(*str1);
	free(*str2);
	*str = NULL;
	*str1 = NULL;
	*str2 = NULL;
}
//----------------------------------------------------------------

/*
void	get_t_cl_in_list(t_src *data)
{
	char	*str[3];

	str[0] = NULL;
	str[1] = NULL;
	str[2] = NULL;
	tokens_list_start(data);
<<<<<<< HEAD
	while (data->token_list )
=======
	while (data->token_list)
>>>>>>> Artur
	{
		//&& data->token_list->next != NULL whilic jnjel em
		if (data->token_list && data->token_list->type != 0)
		{
			str[0] = ft_strjoin(str[0], data->token_list->token);
			if (data->token_list->type > 0 && data->token_list->type < 5)
			{
							printf(">>> ste_chi_05<<<\n");
				get_t_cl_in_list_heredoc(data, str[1], &str[0]);

				<< H << l cat > 
			}
			else
			{
					printf(">>> ste_chi_04<<<\n");
				
				str[2] = ft_strjoin(str[2], data->token_list->token);
			}
		}
		if (data->token_list && (data->token_list->type == 0
				|| data->token_list->next == NULL))
		{
			data->cl_in = new_node_t_cl_in(str[0], str[1], str[2], data->cl_in);
<<<<<<< HEAD
			if(data->cl_in->prev == NULL)
=======
			if (data->cl_in->prev == NULL)
>>>>>>> Artur
				data->clin_head = data->cl_in;
			func_norm_get_t_cl_in_list(&str[0], &str[1], &str[2]);
		}
		data->token_list = data->token_list->next;
	}
	data->clin_last = data->cl_in;
	data->cl_in = data->clin_head ;
	//print_t_cl_in(data);
	free_token(data);
}
*/

//______--------------__________-----____---_---_-_--_--_--_--_-------------_--_-_-__--_--_-______









void	get_t_cl_in_list(t_src *data)
{

	int i = 0;
	char *s = 0;
	char *s1 = 0;
	char **herdoc = 0;
	t_cl_in *cl_in = 0;
	int flag;


	tokens_list_start(data);
	t_tokens *tmp = data->token_list;
	data->cl_in = 0;

	data->cl_in = new_node_t_cl_inPPP(data->cl_in);
	cl_in = data->cl_in;
	while (tmp)
	{
		flag = 0;
		if (tmp->type == 0)
		{
			i++;
			cl_in = new_node_t_cl_inPPP(cl_in);
			cl_in->index_herdoc = i;
		}
		if (tmp->type == 2)
		{
			s = NULL;
			s1 = NULL;
			herdoc = 0;
			s1 = ft_strdup(tmp->token);
			if (tmp->next)
				tmp = tmp->next;
			if (tmp && tmp->next && tmp->type == 8)
				tmp = tmp->next;
			while (tmp && tmp->type >= 5 && tmp->type <= 7)
			{
				s = ft_strjoin_1(s1, tmp->token);
				free(s1);
				s1 = s;
				s = NULL;
				tmp = tmp->next;
				flag = 1;
			}
			herdoc = ft_strjoin_double_point(cl_in->heredoc, s1);
			free(cl_in->heredoc);
			cl_in->heredoc = herdoc;
			cl_in->counthirdoc++;
			//printf("===================%d ===============\n",cl_in->counthirdoc);
		}
		if (tmp && (flag == 0))
			tmp = tmp->next;
	}
}

t_cl_in	*new_node_t_cl_inPPP(t_cl_in *cl_in)
{
	t_cl_in	*node;

	node = (t_cl_in *)malloc(sizeof(t_cl_in));
	if (!node)
		return (0);
	node->index_herdoc = 0;
	node->word = 0;
	node->oll = 0;
	node->heredoc = 0;
	node->counthirdoc = 0;
	node->in_fd = -2;
	node->out_fd = -2 ;
	node->next = NULL;
	node->prev = cl_in;
	if (cl_in)
		cl_in->next = node;
	return (node);
}

t_cl_in	*new_node_t_cl_in(char *str, char *str1, char *str2, t_cl_in *cl_in)
{
	t_cl_in	*node;

	node = (t_cl_in *)malloc(sizeof(t_cl_in));
	if (!node)
		return (0);
	if (str)
		node->oll = ft_strdup(str);
	if (str2)
		node->word = ft_split(str2, ' ');
	if (str1)
		node->heredoc = ft_split(str1, ' ');
	if (node->word && node->word[0])
		node->id = ft_strdup(node->word[0]);
	else
		node->id = NULL;
	node->pip_her_doc[0] = -2;
	node->pip_her_doc[1] = -2 ;
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
	while (tmp && tmp->prev != NULL)
	{
		tmp = tmp->prev;
	}
	while (tmp)
	{
		// printf("id = [%s]\n", tmp->id);
		printf("\n\n\n\ncounthirdoc = [%d]\n", tmp->counthirdoc);
		printf("index_herdoc = [%d]\n", tmp->index_herdoc);
		// i = -1;
		// while(tmp->word && tmp->word[++i])
			// printf("word%d = [%s] \n",i, tmp->word[i]);
		i = -1;
		while(tmp->heredoc && tmp->heredoc[++i])
			printf("heredoc%d = [%s] \n",i, tmp->heredoc[i]);
		// printf("oll = [%s]\n", tmp->oll);
		tmp = tmp->next;
	}
}
