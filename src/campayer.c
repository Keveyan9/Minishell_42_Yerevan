/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   campayer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:49:38 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/06 00:12:10 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"minishell.h"

static void	have_key(t_export *var)
{
	if (var->add)
	{
		var->addstring = ft_strjoin(var->find_key->value, var->value);
		free(var->find_key->value);
		var->find_key->value = var->addstring;
	}
	else
	{
		free(var->find_key->value);
		var->find_key->value = var->value;
	}
}

static int	clin_creat(char **s, int lenqt)
{
	*s = (char *)malloc(sizeof(char) * lenqt);
	if (!s)
		return (1);
	return (0);
}

static int	creat_chanch_nod(t_export *var, t_src *data)
{
	t_env	*newnode;

	newnode = NULL;
	var->find_key = find_env(data->env, var->key);
	if (var->find_key)
		have_key(var);
	else
	{
		newnode = new_node();
		if (!newnode)
			return (1);
		newnode->key = ft_strdup(var->key);
		newnode->value = ft_strdup(var->value);
		free_give_null(&var->key);
		free_give_null(&var->value);
		put_env_node(data, newnode);
	}
	return (0);
}

static int	coll_creat_nod(t_src *data, t_export *var)
{
	t_env	*newnode;

	newnode = NULL;
	if (chek_key(data->cl_in->word[var->row]))
		return (1);
	newnode = new_node();
	if (!newnode)
		return (1);
	newnode->key = ft_strdup(data->cl_in->word[var->row]);
	put_env_node(data, newnode);
	return (0);
}

int	campeyr(t_src *data, t_export *var)
{
	if (var->i)
	{
		if (data->cl_in->word[var->row][var->i - 2] == '+')
			var->add = 1;
		clin_creat(&(var->key), (var->i + 1 - var->add));
		ft_strlcpy(var->key, data->cl_in->word[var->row], var->i - var->add);
		clin_creat(&(var->value), (var->string_len - var->i));
		ft_strlcpy(var->value, &(data->cl_in->word[var->row][var->i]),
			var->string_len - var->i + 1);
		if (chek_key(var->key))
		{
			free_give_null(&var->key);
			free_give_null(&var->value);
			return (1);
		}
		if (creat_chanch_nod(var, data))
			return (1);
	}
	else if (coll_creat_nod(data, var))
		return (1);
	return (0);
}
