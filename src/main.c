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

int	g_flags;

static void	handler_main(int sig)
{
	(void)sig;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_replace_line("", 0);
	rl_on_new_line();
}

static void	main_logica(t_src *data)
{
	int	print_resurs_f;

	print_resurs_f = 0;
	free_token(data);
	if (data->pipes_count > 500)
	{
		data->pipes_count = 500;
		print_resurs_f = 1;
	}
	if (data->syntax_err != 0)
		print_syntax_err(data);
	creat_here_doc(data);
	if (!g_flags && data->syntax_err == 0 && data->cl_in
		&& data->cl_in->word)
	{
		if (data->pipes_count == 0 && data->cl_in->word [0])
			alone(data);
		else
			realaysing(data);
		data->cl_in = data->clin_head;
	}
	else
		close_herdoq_fd(data);
	if (print_resurs_f)
		printf("you won't use more than 500 proces\n");
}

int	main(int ac, char **av, char **env)
{
	t_src	*data;

	(void)ac;
	(void)av;
	data = malloc(sizeof(t_src));
	if (!data)
		return (0);
	if (all_input(data, env))
		return (0);
	shell_level(data);
	while (1 && data->pid > 0)
	{
		g_flags = 0;
		signal(SIGINT, handler_main);
		signal(SIGQUIT, SIG_IGN);
		start_input(data);
		ft_read_l(data);
		data = syntax_error(data);
		get_t_cl_in_list(data);
		main_logica(data);
		free_clin(data);
		free_give_null(&data->line);
	}
	oll_free(data);
	return (0);
}
