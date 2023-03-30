/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:33:21 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 16:33:37 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int find_index(char *s, char c)
{
	int i;

	i = 0;
	printf("find__%s__\n",s);
	while (s[i])
		if (s[i++] == c)
			return (i);
	return (0);
}

static int chek_key(char *s)
{
	size_t n;
	char *wrong_arg;

	n = 0;

	if (ft_isalpha(s[0]))
		while (s[n] == '_' || ft_isalnum(s[n]))
			n++;
	if (n == ft_strlen(s))
		return (0);
	wrong_arg = ft_strjoin("is non corect key", s);
	write(1, "\n", 1);
	write(1, wrong_arg, ft_strlen(wrong_arg));
	free(wrong_arg);
	wrong_arg = NULL;
	return (1);
}

static int clin_creat(char **s, int lenqt)
{
	*s = (char *)malloc(sizeof(char) * lenqt);
	if (!s)
		return (1);
	return (0);
}

static int creat_chanch_nod(t_export *var, t_src *data)
{
	t_env *newnode;

	newnode = NULL;
	var->find_key = find_env(data->env, var->key);
	if (var->find_key)
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
	else
	{
		newnode = new_node();
		if (!newnode)
			return (1);
		newnode->key = ft_strdup(var->key);
		newnode->value = ft_strdup(var->value);
		put_env_node(data, newnode);
	}
	return (0);
}

static int campeyr(t_src *data, t_export *var)
{
	t_env *newnode;

	newnode = NULL;
	if (var->i)
	{
		if (data->cl_in->word[var->row][var->i - 2] == '+')
			var->add = 1;
		clin_creat(&(var->key), (var->i + 1 - var->add));
		ft_strlcpy(var->key, data->cl_in->word[var->row], var->i - var->add);
		clin_creat(&(var->value), (var->string_len - var->i));
		ft_strlcpy(var->value, &(data->cl_in->word[var->row][var->i]), var->string_len - var->i + 1);
		if (chek_key(var->key))
		{
			free(var->key);
			free(var->value);
			return (1);
		}
		if (creat_chanch_nod(var, data))
			return (1);
	}
	else
	{
		if (chek_key(data->cl_in->word[var->row]))
			return (1);
		newnode = new_node();
		if (!newnode)
			return (1);
		newnode->key = ft_strdup(data->cl_in->word[var->row]);
		newnode->value = NULL;
		put_env_node(data, newnode);
	}
	return (0);
}

void export(t_src *data)
{
	t_export var;
	char *non_valid_arg;

	var.value = NULL;
	var.key = NULL;
	var.add = 0;
	var.row = 1;
	if (data->cl_in->word[1])
	{
		while (data->cl_in->word[var.row])
		{
			var.i = 0;
			var.string_len = 0;
			if (!ft_isalpha(data->cl_in->word[var.row][0]))
			{
				non_valid_arg = ft_strjoin("is not valid argumwent name", data->cl_in->word[var.row]);
				write(1, non_valid_arg, ft_strlen(non_valid_arg));
				write(1, "\n", 1);
				free(non_valid_arg);
				data->error = 1;
				break;
			}
			var.i = find_index(data->cl_in->word[var.row], '=');
			var.string_len = ft_strlen(data->cl_in->word[var.row]);
			if (campeyr(data, &var))
			{
				data->error = 1;
				break;
			}
			else
				data->error = 0;
			var.row++;
		}
	}
	else
		print_export(data);
}
