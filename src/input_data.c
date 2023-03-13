/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:28:12 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/05 14:26:03 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/minishell.h"
#include "minishell.h"

int new_node(t_src *data)
{
	t_env *node;

	node = (t_env *)malloc(sizeof(t_env));
	if (!node)
		return (1);
	node->next = NULL;
	while (data->env && data->env->next != NULL)
		data->env = data->env->next;
	if (data->env)
	{
		node->prev = data->env;
		data->env->next = node;
		data->env = node;
	}
	else
	{
		node->prev = NULL;
		data->env = node;
	}
	return (0);
}

int start_input_env(char **env, t_src *data)
{
	int i;
	int k;
	size_t len;
	data->env = NULL;

	len = 0;
	i = 0;
	k = 0;

	while (env[i])
	{
		len = ft_strlen(env[i]);
		k = ft_strchr_mod(env[i], '=');
		if (new_node(data))
		{
			printf("can not creat env_list\n");
			return (1);
		}
		data->env->key = (char *) malloc(sizeof(char ) * (k + 1));
		data->env->value = (char *) malloc (sizeof(char) * (len - k + 1));
		if(!(data->env->key)&& data->env->value)
			return (1);
		ft_strlcpy(data->env->key, env[i], k + 1);
		ft_strlcpy(data->env->value, &(env[i][k + 1]), (len - k));
		data->env->flag_p = 0;
		i++;
	}
	while (data->env->prev)
		data->env = data->env->prev;
	return (0);
}

int all_input(t_src *data, char **env)
{
	start_input(data);
	return (start_input_env(env, data));
}

void start_input(t_src *data)
{
	data->line = NULL;
	data->index_s_err = 0;
	data->syntax_err = 0;
	data->doubl_quotes = 0;
	data->single_quotes = 0;
	data->error = 0;
	data->pipes_count = 0;
	data->ferst_child = 0;
	data->ciqel = 0;
	data->ferst_child = 0;
	data->token_list = NULL;
	data->cl_in = NULL;
}
