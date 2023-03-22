/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:20:59 by skeveyan          #+#    #+#             */
/*   Updated: 2023/02/28 16:21:29 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static void	call_dolar(char *s, t_src *data, int n)
{
	char *error;
	n++;
	while (s[n] && !(s[n] > 20 && s[n] < 65))
		n++;
	while (s[n])
	{
		if (s[n - 1] == '$' && s[n] == '?')
		{
			 error = ft_itoa(data->error);
			 write(1,error,ft_strlen(error));
			 free(error);
			 error = NULL;
			n = n + 2;
		}
		else
		{
			write(1, &s[n], 1);
			n++;
		}
	}
}

static void	echo_print(t_src *data, size_t *calem, int *row, int *flag)
{
	while (data->cl_in->word[*calem])
	{
		while (data->cl_in->word[*calem][*row])
		{
			if (data->cl_in->word[*calem][*row] == '$')
			{
				call_dolar(data->cl_in->word[*calem], data, *row);
				break ;
			}
			else
				write(1, &(data->cl_in->word[*calem][(*row)++]), 1);
		}
		if ((data->cl_in->word[*calem + 1]) && \
			((*calem >= 2 && *flag == 0) || (*calem >= 1 && *flag == 1)))
			write(1, " ", 1);
		*row = 0;
		(*calem)++;
	}
		if (*flag)
			write(1, "\n", 1);
}

void	echo(t_src *data)
{
	size_t	calem;
	int	row;
	int	flag;

	calem = 1;
	flag = 1;
	row = 0;
	if (data->cl_in->word[1] && data->cl_in->word[1][0] == '-' && data->cl_in->word[1][1] == 'n')
	{
		while (data->cl_in->word[1][++calem] == 'n')
			;
		if ((ft_strlen(data->cl_in->word[1])) == calem)
		{
			calem = 2;
			flag = 0;
		}
		else
			calem = 1;
	}
	else
		calem = 1;
	echo_print(data, &calem, &row, &flag);
}
