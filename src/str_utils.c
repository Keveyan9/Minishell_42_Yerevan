/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:49:01 by artadevo          #+#    #+#             */
/*   Updated: 2023/02/20 23:10:57 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char *ft_str_env_cmp(char const *s, int start, int end)
{
	int i;
	char *str;

	i = start;
	while (s[i] && i <  end)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	i = 0;
	while (s[start + i] && i <= (end - start))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int ft_strchr_mod(const char *s, char c)
{
	int i;
	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

void error_print(char *s, char *c)
{
	printf("\n%d\n", (int)ft_strlen(c));
	write(2, s, ft_strlen(s));
	write(2, c, ft_strlen(c));
	write(2, "\'\n", 2);
}

//---es togic heto sax jnji------V
void write_env_list(t_env *node, char **env)
{
	int i = 0;

	while (node->next)
	{
		printf("env-> [%s]\n", env[i]);
		printf("key-> [%s]\nvalue-> [%s]\n", node->key, node->value);
		node = node->next;
		i++;
	}
}
