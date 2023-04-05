/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:53:11 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/30 21:07:51 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_str_n_dup(const char *s, int x)
{
	char	*str;
	int		i;

	i = 0;
	if (!s || !*s)
		return (NULL);
	str = malloc(sizeof(char) * (x + 1));
	while (i < x && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	check_quots_norm(char *str, int *j, int *i)
{
	*j = *i;
	if (*j > 0)
		(*j)--;
	while (str[++(*i)] != 34 && str[*i] != '\0')
		;
}

int	check_quots(t_src *data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = data->line;
	while (str[i] != '\0')
	{
		if (str[i] == 34)
		{
			check_quots_norm(str, &j, &i);
			if (!str[i])
			{
				new_line(data, j, 34);
				return (1);
			}
			else
				i++;
		}
		else if (error_search_error2(data, str, &i) != 0)
			return (1);
	}
	return (1);
}

int	error_search_error2(t_src *data, char *str, int *i)
{
	int	j;

	if (str[*i] == 39)
	{
		j = *i;
		if (j > 0)
			j--;
		while (str[*i] != '\0' && str[++(*i)] != 39)
			;
		if (!str[*i])
		{
			new_line(data, j, 39);
			return (1);
		}
		else
			(*i)++;
	}
	if (str[*i] != '\0' && str[*i] != 34 && str[*i] != 39)
		(*i)++;
	return (0);
}
