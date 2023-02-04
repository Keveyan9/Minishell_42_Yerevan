/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:37:41 by artadevo          #+#    #+#             */
/*   Updated: 2023/02/04 13:55:19 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// t_tokens	*new_node_tokens(char *s, int k, t_tokens *token_list)
// {
// 	t_tokens	*node;
// 	int			i;

// 	i = 0;
// 	node = (t_tokens *)malloc(sizeof(t_tokens));
// 	if (!node)
// 		return (0);
// 	node->len = (int)ft_strlen(s);
// 	node->token = s;
// 	node->type = k;
// 	node->next = NULL;
// 		node->prev = token_list;
// 	if (token_list)
// 		token_list->next = node;
// 	return (node);
// }

// t_tokens	*lexer(char *line)
// {
// 	t_tokens	*tokens;
// 	t_tokens	*tmp_tok;
// 	int		i;	

// 	i = 0;
// 	tokens = ft_calloc(sizeof(t_tokens), 1);
// 	while (line[i])
// 	{
// 		if (line[i] && (is_word_tok(line[i]) == 0 || line[i] == '|'
// 				|| line[i] == ' ' || line[i] == '"' || line[i] == '\''))
// 			norm_lexer(line, &i, &tokens);
// 		else if (line[i] && line[i] == '<' && line[i + 1] != '<')
// 			make_redin_tok(&tokens, line, &i);
// 		else if (line[i] && line[i] == '<' && line[i + 1] == '<')
// 			make_here_tok(&tokens, line, &i);
// 		else if (line[i] && line[i] == '>' && line[i + 1] != '>')
// 			make_redout_tok(&tokens, line, &i);
// 		else if (line[i] && line[i] == '>' && line[i + 1] == '>')
// 			make_apply_tok(&tokens, line, &i);
// 	}
// 	tmp_tok = tokens->next;
// 	free(tokens);
// 	return (tmp_tok);
// }
