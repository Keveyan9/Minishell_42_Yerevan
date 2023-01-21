/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:55:16 by artadevo          #+#    #+#             */
/*   Updated: 2023/01/21 19:57:20 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum s_type
{
	PIPE,
	REDIR_OUT,   	// >
	REDIT_APPEND, 	// >>
	REDIR_IN, 		// <
	HEREDOC, 		// <<
	WORD, 			// words
	EXP_FIELD, 		// "..." kam '...'
	UNDEFINED, 		// >>> <<< |||
	SEP,
}	t_type;

typedef struct s_env
{
	char			*key;
	char			*value;

	int				flag;

	struct s_env	*next;
	struct s_env	*prev;
}t_env;

typedef struct s_tokens
{
	int				len;
	char			*token;
	int				type;

	struct s_tokens	*next;
	struct s_tokens	*prev;
}t_tokens;

typedef struct s_src
{
	char		*line;
	int			syntax_err;
	t_tokens	*tmp;
	t_env		*env;
}t_src;

//------src-------main.c------------------

//------src-------start_pars.c------------
t_src	*ft_parser(t_src *data);

//------read------read_input.c------------
void	ft_read_l(t_src *data);

//------corector------line_corector.c-------
char	*line_corector(char *line);
//------corector------syntax_error.c-------
t_src	*find_syntax_error(t_src *data);
//------input------input_data.c------------
t_src	*start_input(t_src *data, char **env);
t_env	*start_input_env(char **env);
//------utils------str_utils.c------------
size_t	ft_strlen(const char *s);
int		ft_strchr_mod(const char *s, char c);
char	*ft_str_env_cmp(char const *s, int start, int end);
void	error_print(char *s, char *c);

void write_env_list(t_env *node, char **env); // verjum jnji

#endif
