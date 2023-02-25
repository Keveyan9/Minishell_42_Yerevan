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
		t_cl_in *in;
		pid_t pid;
		(void)ac;
		(void)av;
		int flag = 1;
		data = malloc(sizeof(t_src));
		pid = 0;
			if (!data)
				return (0);
			start_input(data, env);
			 data->ferst_child = 0;
			 data->pipes_count = 1;
		 clin(data);
		// coll_comands(data);
			if(data->pipes_count == 0 && chek_coll_builtin(data) == 0);
			else
			 {
				 //pipe(data->pip);
				 data->pipes_count++;
						pipe(data->pip);
				 while (pid == 0 && data->pipes_count--)
				 {
					 //usleep(1000);
						pid = fork();
						if(pid < 0)
						{
							write(1,"can not creat child\n",20);
							break;
						}
						if(pid == 0)
						{
							data->cl_in = data->cl_in->next;
							data->ferst_child++;
						}
				 }
				if(pid > 0)
						child(data);
					if(pid == 0)
						 wait(NULL);
				//printf("free");
				oll_free(data);
		 }
	 
			return (0);
}