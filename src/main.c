/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:50:44 by artadevo          #+#    #+#             */
/*   Updated: 2023/01/22 20:12:31 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int main(int ac, char **av, char **env)
{
	t_src *data;
	int error;
	t_env *origin;
	(void)ac;
	(void)av;
	data = malloc(sizeof(t_src));
	if (!data)
		return (0);
	start_input(data, env);

	//origin = data->env;
	// while (origin)
	// {
	// 	printf("%s = %s\n", origin->key, origin->value);
	// 	origin = origin->next;
	// }

	data->token_list = (t_tokens *)malloc(sizeof(t_tokens));
	if (!data->token_list)
		return (0);
	data->token_list->token = ft_strdup("cd src");
	// printf(" token --%s\n", data->token_list->token);
	// cd(data);
	// pwd();
	// 	data->token_list->token = ft_strdup("cd ../../01");
	// printf(" token --%s\n", data->token_list->token);
	// cd(data);
	//  origin = data->env;
	// while (origin)
	// {
	// 	printf("# %s = %s\n", origin->key, origin->value);
	// 	origin = origin->next;
	// }
	//pwd();
	env_f(data);
	//while(1);
	 return (0);
}