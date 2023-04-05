/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  chek_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:49:38 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 15:49:46 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	chek_key(char *s)
{
	size_t	n;
	char	*wrong_arg;

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
