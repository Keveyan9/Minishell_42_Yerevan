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

t_env *new_node()
{
	t_env *node;

	node = (t_env *)malloc(sizeof(t_env));
	if (!node)
	{
		write(1, "can not env malloc\n", 19);
		return (NULL);
	}
	node->flag_p = 0;
	node->place = 0;
	node->key = NULL;
	node->value = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int put_env_node(t_src *data, t_env *node)
{
	if (data && node)
	{
		if (!data->env)
		{
			data->env = node;
			data->envhead = node;
			data->envlast = node;
		}
		else
		{
			node->prev = data->envlast;
			data->envlast->next = node;
			data->envlast = node;
		}
		return (0);
	}
	return (1);
}

int start_input_env(char **env, t_src *data)
{
	int i;
	int k;
	size_t len;
	t_env *newnode;

	len = 0;
	i = 0;
	k = 0;
	while (env[i])
	{
		len = ft_strlen(env[i]);
		k = ft_strchr_mod(env[i], '=');
		newnode = new_node();
		if (!newnode)
			return (1);
		newnode->key = (char *)malloc(sizeof(char) * (k + 1));
		newnode->value = (char *)malloc(sizeof(char) * (len - k + 1));
		if (!(newnode->key) && !(newnode->value))
			return (1);
		ft_strlcpy(newnode->key, env[i], k + 1);
		ft_strlcpy(newnode->value, &(env[i][k + 1]), (len - k));
		if (put_env_node(data, newnode))
			return (1);
		i++;
	}
	return (0);
}

int all_input(t_src *data, char **env)
{
	data->env = NULL;
	start_input(data);
	data->home_path = getcwd(NULL,0);
	data->error = 0;
	return (start_input_env(env, data));
}

void start_input(t_src *data)
{
	data->line = NULL;
	data->index_s_err = 0;
	data->syntax_err = 0;
	data->doubl_quotes = 0;
	data->single_quotes = 0;
	data->pipes_count = 0;
	data->pip_doing = 0;
	data->cycle = 0;
	data->token_list = NULL;
	data->cl_in = NULL;
	data->pid = 1;
}
