/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolar_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:25:21 by skeveyan          #+#    #+#             */
/*   Updated: 2023/04/06 00:08:06 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	key_finish(char *s)
{
	int	n;

	n = 0;
	while (s[n] && s[n] != '$' && s[n] != ' ')
		n++;
	return (n);
}

static void	find_chanche_key(t_env *env, char **key)
{
	t_env	*place;

	place = find_env(env, *key);
	free(*key);
	*key = NULL;
	if (place)
		*key = ft_strdup(place->value);
}

static void	gluing(char **string, char **start, char **key, char **remiander)
{
	char	*full;

	full = ft_strjoin(*start,*key);
	free_give_null(string);
	*string = ft_strjoin(full, *remiander);
	free_give_null(&full);
	free_give_null(start);
	free_give_null(key);
	free_give_null(remiander);
}

void	chek_dolar_change(t_env *env, char **string, int flag, t_src *data)
{
	char	*key;
	char	*remainder;
	char	*start;
	int		n;
	int		antil;

	n = -1;
	if (flag == 6)
		return ;
	while ((*string)[++n])
	{
		if ((*string)[n] == '$' && (*string)[n + 1])
		{
			antil = key_finish(&(*string)[n + 1]);
			start = ft_substr((*string), 0, n);
			if ((*string)[n + 1] == '?')
			{
				key = ft_itoa(data->error);
				remainder = ft_substr((*string), n + 2, ft_strlen (*string));
			}
			else
			{
				key = ft_substr((*string), n + 1, antil);
				remainder = ft_substr((*string), n + antil +1,
						ft_strlen (*string));
				find_chanche_key(env, &key);
			}
			gluing(string, &start, &key, &remainder);
		}
	}
}
