/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:55:16 by artadevo          #+#    #+#             */
/*   Updated: 2023/02/27 21:46:09 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>

# include "../libft/libft.h"

typedef enum s_type
{
	PIPE,				// |		0
	REDIR_APPEND, 		// >>		1
	HEREDOC, 			// <<		2
	REDIR_OUT,   		// >		3
	REDIR_IN, 			// <		4
	WORD, 				// words	5
	EXP_QUOTES_SINGLE,	// '...'	6
	EXP_QUOTES_DOUBL, 	// "..."	7
	SPACE,				//			8
}	t_type;

typedef struct s_env
{
	char			*key;
	char			*value;

	int				flag;

	struct s_env	*next;
	struct s_env	*prev;
}t_env;

typedef struct s_cmand
{
	char			*key;
	char			**value;

	int				flag;

	struct s_env	*next;
	struct s_env	*prev;
}t_cmand;

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
	int			index_s_err;
	int			syntax_err;
	int			doubl_quotes;
	int			single_quotes;
	int			count_pipe;
	t_tokens	*token_list;
	t_env		*env;
}t_src;

//------src-------main.c------------------

//------src-------get_tokens.c------------------
t_src		*get_tokens(t_src *data);
t_tokens	*new_node_tokens(char *s, int k, t_tokens *token_list);
void		tokens_list_start(t_src *data);
void		tokens_list_last(t_src *data);

//------src-------get_tokens_utils1.c------------------
t_src		*find_word(char *s, t_src *data);
t_src		*find_space(char *s, t_src *data);
t_src		*find_pipe(char *s, t_src *data);
t_src		*find_single_quotes(char *s, t_src *data);
t_src		*find_duobl_quotes(char *s, t_src *data);
//------src-------get_tokens_utils2.c------------------
t_src		*find_redir_append(char *s, t_src *data);
t_src		*find_hierdoc(char *s, t_src *data);
t_src		*find_redir_in(char *s, t_src *data);
t_src		*find_redir_out(char *s, t_src *data);
void	    print_tokens(t_src *data); // heto jnji

//------src-------start_pars.c------------
t_src		*ft_parser(t_src *data);

//------src------read_input.c------------
void		ft_read_l(t_src *data);

//------src------line_corector.c-------
char		*line_corector(char *line);

//------src------syntax_error.c-------
t_src		*syntax_error(t_src *data);
int			get_count(char *s, char c);
int			get_index_quotes(t_src *data);
int			check_and_break_parentheses(t_src *data);

//------src------syntax_error_add.c-------
void		add_sintex_error(t_src *data);
int			get_pipe_syntax_err(t_src *data);
int			get_redir_syntax_err(t_src *data);

//------src------syntax_error_utils.c-------
void		get_frst_element(char *s, t_src *data);
void		print_eyntax_err(t_src *data);

//------src------input_data.c------------
t_src		*all_input(t_src *data, char **env);
t_src		*start_input(t_src *data);
t_env		*start_input_env(char **env);
//------src------str_utils.c------------
int			ft_strchr_mod(const char *s, char c);
char		*ft_str_env_cmp(char const *s, int start, int end);
void		error_print(char *s, char *c);

void 		write_env_list(t_env *node, char **env); // verjum jnji

#endif
