/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:50:44 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/31 00:18:04 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// ls <<a >>d >a <v <"a" >"w"

// #include <termios.h>

//pwd | >a <<h << es stex mtacel em vor koxqe hastat anun ka ete anun chka piti ta anexpedit token ta u 
//pwd | wc -l >b |  >a <<h >>  orinak es paragayum el b piti chstexci

static void handler_main(int sig)
{
    (void)sig;
    ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	
}

static void start_doing(t_src *data)
{
	printf("__%d__\n",data->pipes_count);
	if (data->pipes_count == 0 && data->cl_in->word)
		alone(data);
	else
		realaysing(data);
	data->cl_in = data->clin_head;
	if (data->cl_in)
		free_clin(data);
	free(data->line);
	data->line = NULL;
}



int main(int ac, char **av, char **env)
{
	t_src *data;

	(void)ac;
	data = malloc(sizeof(t_src));
	if (!data)
		return (0);
	if (all_input(data, env))
		return (0);
	shell_level(data, av);
	while (1 && data->pid > 0)
	{ 
		g_flags = 0;
		signal(SIGINT, handler_main);
		signal(SIGQUIT, SIG_IGN);
		start_input(data);
		ft_read_l(data);
		data = syntax_error(data);
		get_t_cl_in_list(data);
		free_token(data);
		creat_here_doc(data);
		if(!g_flags && data->syntax_err == 0 && data->cl_in)
		 	start_doing(data);
		if(data->syntax_err != 0)
			print_syntax_err(data);
	}
	oll_free(data);
	return (0);
}
