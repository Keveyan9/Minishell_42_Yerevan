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

int	find_index(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
		if (s[i++] == c)
			return (i);
	return (0);
}

static int	chek_key(char *s)
{
	int	n;

	n = 0;
	if (ft_isalpha(s[0]))
		while (s[n] == '_' || ft_isalnum(s[n]))
			n++;
	if (n == ft_strlen(s))
		return (0);
	printf(": %s : not a valid identifier\n", s);
	return (1);
}

static int	clin_creat(char **s, int lenqt)
{
	*s = (char *)malloc(sizeof(lenqt));
	if (!s)
		return (1);
	return (0);
}

static void	creat_chanch_nod(t_export *var, t_src *data)
{
	t_env	*new_nod;

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
		new_nod = new_node(data->env);
		new_nod->key = ft_strdup(var->key);
		new_nod->value = ft_strdup(var->value);
	}
}

void	export(t_src *data)
{
	t_export	var;
	t_env		*new_nod;

	var.value = NULL;
	var.key = NULL;
	var.add = 0;
	var.row = 1;
	if (data->cl_in->word[1])
	{
		while (data->cl_in->word[var.row])
		{
			if (!ft_isalpha(data->cl_in->word[var.row][0]))
			{
				printf("is not valid argument %s\n", data->cl_in->word[var.row]);
				break ;
			}
			var.i = find_index(data->cl_in->word[var.row], '=');
			var.string_len = ft_strlen(data->cl_in->word[var.row]);
			if (var.i)
			{
				if (data->cl_in->word[var.row][var.i - 2] == '+')
					var.add = 1;
				clin_creat(&(var.key), (var.i + 1 - var.add));
				ft_strlcpy(var.key, data->cl_in->word[var.row], var.i - var.add);
				free(var.key);
				clin_creat(&(var.value), (var.string_len - var.i));
				ft_strlcpy(var.value, &(data->cl_in->word[var.row][var.i]), var.string_len - var.i + 1);
				free(var.value);
				if (chek_key(var.key))
					break ;
				creat_chanch_nod(&var, data);
			}
			else
			{
				if (chek_key(data->cl_in->word[var.row]))
					break ;
				new_nod = new_node(data->env);
				new_nod->key = ft_strdup(data->cl_in->word[var.row]);
				new_nod->value = NULL;
			}
			var.row++;
		}
	}
	else
		print_export(data);
}
