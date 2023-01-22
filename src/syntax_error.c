/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:30:42 by artadevo          #+#    #+#             */
/*   Updated: 2023/01/22 20:13:39 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokens	*new_node_tokens(char *s, int k, t_tokens *token_list)
{
	t_tokens	*node;
	int			i;

	i = 0;
	node = (t_tokens *)malloc(sizeof(t_tokens));
	if (!node)
		return (0);
	node->len = (int)ft_strlen(s);
	node->token = s;
	node->type = k;
	node->next = NULL;
		node->prev = token_list;
	if (token_list)
		token_list->next = node;
	return (node);
}

//   []
// void	get_redial(char *str, int *i, t_src *data)
// {
// 	char	*s;
// 	int		k;

// 	k = &i;
// 	if (str[k] == '>' && str[k] != '>')
// 	{
// 		s = ">";
// 		data->token_list = new_node_tokens(s , );
// 	}
// }

// t_src	*syntax_error(t_src *data)
// {
// 	char		*str;
// 	int			i;

// 	i = -1;
// 	str = data->line;
// 	data->token_list = NULL;
// 	// while (str[++i])
// 	// {
// 	// 	if (str[i] == '>' || str[i] == '<')
// 	// 		get_redial(&str[i], &i, &data);
// 	// 	else if (str[i] == ' ')
// 	// 		tmp = ????;
// 	// 	else if (str[i] == '|')
// 	// 		tmp = ????;
// 	// 	else if (str[i] == '\'' || str[i] == '\"')
// 	// 		tmp = ????;
// 	// 	else 
// 	// 		tmp = ????;
// 	// }
// 	return (data);
// }

int	check_frst_bite(char c, char *s)
{
	int		i;
	char	t[2];

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			t[0] = c;
			t[1] = '\0';
			error_print(" syntax error near unexpected token `", t);
			return (128);
		}
		i++;
	}
	return (0);
}