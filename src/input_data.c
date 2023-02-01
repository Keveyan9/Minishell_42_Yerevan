/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:28:12 by artadevo          #+#    #+#             */
/*   Updated: 2023/01/22 20:08:09 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env *new_node(t_env *env_list)
{
	t_env *node;

	node = (t_env *)malloc(sizeof(t_env));
	if (!node)
		return (0);
		while (env_list && env_list->next != NULL)
			env_list = env_list->next;
		
	node->next = NULL;
	node->prev = env_list;
	if (env_list)
		env_list->next = node;
	return (node);
}

t_env *start_input_env(char **env)
{
	t_env *env_list;
	int i;
	int k;

	i = 0;
	k = ft_strchr_mod(env[i], '=');
	// i chench in hear thats new_ned need doing only creat now nod it wrong when great and give valu
	env_list = new_node( NULL);
	env_list->key = ft_str_env_cmp(env[i], 0, k - 1);
	env_list->value = ft_str_env_cmp(env[i], k + 1, ft_strlen(env[i]));
	env_list->flag = 0; // karoga heto petq lini popoxel kamel che????
	i++;
	while (env[i])
	{
		k = ft_strchr_mod(env[i], '=');
		env_list = new_node(env_list);
		env_list->key = ft_str_env_cmp(env[i], 0, k - 1);
		env_list->value = ft_str_env_cmp(env[i], k + 1, ft_strlen(env[i]));
		env_list->flag = 0; // karoga heto petq lini popoxel kamel che????
		i++;
	}
	while (env_list->prev)
		env_list = env_list->prev;
	// write_env_list(env_list, env);
	return (env_list);
}

void *start_input(t_src *data, char **env)
{
	data->line = NULL;
	data->syntax_err = 0;
	data->env = start_input_env(env);
}
