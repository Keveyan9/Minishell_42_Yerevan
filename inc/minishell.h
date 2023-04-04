/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:55:16 by artadevo          #+#    #+#             */
/*   Updated: 2023/03/31 00:10:11 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include <sys/ioctl.h>

extern int g_flags;


typedef enum s_type
{
	PIPE,			   // |		0
	REDIR_APPEND,	   // >>		1
	HEREDOC,		   // <<		2
	REDIR_OUT,		   // >		3
	REDIR_IN,		   // <		4
	WORD,			   // words	5
	EXP_QUOTES_SINGLE, // '...'	6
	EXP_QUOTES_DOUBL,  // "..."	7
	SPAC,			   //			8
}	t_type;

typedef struct s_env
{
	char			*key;
	char			*value;
	int				flag_p;
	int				place;

	struct s_env	*next;
	struct s_env	*prev;
}t_env;

typedef struct s_tokens
{
	int				len;
	int				syn_err;
	char			*token;
	int				type;

	struct s_tokens	*next;
	struct s_tokens	*prev;
}	t_tokens;

typedef struct s_cl_in
{

	int 	pip_her_doc[2];
	int		index_herdoc;
	char 	**word;
	char 	*oll;
	struct s_cl_in	*next;
	struct s_cl_in	*prev;
}t_cl_in;

typedef struct s_src
{
	char *line;
	int index_s_err;
	int syntax_err;
	int doubl_quotes;
	int single_quotes;
	int error;
	int pipes_count;
	int pip_doing;
	int (*pip)[2];
	int cycle; 	//ciqel
	char *home_path;
	int main_fd_0;
	int	main_fd_1;
	pid_t pid;
	t_tokens *token_list;
	t_tokens *tokens_head;
	t_env *env;
	t_env *envhead;
	t_env *envlast;
	t_cl_in *clin_head;
	t_cl_in * clin_last;
	t_cl_in *cl_in;
} t_src;

typedef struct s_export
{
	int		i;
	int		row;
	int		add;
	int		string_len;
	char	*key;
	char	*value;
	char	*addstring;
	t_env	*find_key;
}			t_export;

typedef struct s_coll_comand
{
	char	**env_aray;
	int		row;
	t_env	*origin;
	char	*key_equal;
	int		i;
}			t_coll_comand;

//------src-------main.c------------------
//------src-------get_tokens.c------------------
t_src		*get_tokens(t_src *data);
t_tokens	*new_node_tokens(char *s, int k, t_tokens *token_list);
void		tokens_list_start(t_src *data);
void		tokens_list_last(t_src *data);
void		token_line_dell(t_tokens *node);

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
void		print_tokens(t_src *data); // heto jnji

//------src------read_input.c------------
void		ft_read_l(t_src *data);
t_env		*new_node(void);
int			put_env_node(t_src *data, t_env *node);
//------src------syntax_error.c-------
t_src		*syntax_error(t_src *data);
void		is_len_delet_spaces(t_src *data, char *s);
int			syntacs_error_redir(char *str, t_src *data, int i);
void		get_pipe_syntax_err2(t_src *data, char *str);

int			syntax_error_search(t_src *data);
//------src------syntax_error_add.c-------

// int			get_pipe_syntax_err(t_src *data);
int			get_pipe_syntax_err(char tokin);
void		add_sintex_error(t_src *data);
int			get_redir_syntax_err(char *tokin, int *i);
int			char_tokin1(char *tokin, int *i);
int			char_tokin1_norm(char *tokin, int *i);

// int			get_redir_syntax_err2(t_src *data);
// int			registor_syn_err(t_src *data, t_tokens *tmp, int syntax_err);

//------src------syntax_error_utils.c-------
void		new_line(t_src *data, int j, int k);
void		get_frst_element(t_src *data);
void		print_syntax_err(t_src *data);
void		get_short_line(t_src *data);
//------src------syntax_error_utils1.c-------
char		*ft_str_n_dup(const char *s, int x);
int			check_quots(t_src *data);
void		check_quots_norm(char *str, int *j, int *i);

//------src------input_data.c------------
int			all_input(t_src *data, char **env);
void		start_input(t_src *data);
int			start_input_env(char **env, t_src *data);
//------src------line_corector.c-------
char		*line_corector(char *line);
//------src------str_utils.c------------
int			ft_strchr_mod(const char *s, char c);
char		*ft_str_env_cmp(char const *s, int start, int end);
void		error_print(char *s, char *c);

//------src------get_t_clin_list.c------------
void		get_t_cl_in_list(t_src *data);
void	join_token_for_clean(t_src *data);
// t_cl_in		*new_node_t_cl_in(t_cl_in *cl_in);
void		print_t_cl_in(t_src *data); // verjum jnji

// builtins
void echo(t_src *data);
void cd(t_src *data);
void pwd(t_src *data);
t_env *find_env(t_env *env, char *s);
void env_f(t_src *data);
void frik(char **s1);
void env_fri(t_env *fri_segment);
void delet_env(t_env *cat_segmeint);
void unset(t_src *data);
void export(t_src *data);
void sort_print_env(t_env *data);
void print_export(t_src *data);
/// logik//
int chek_coll_builtin(t_src *data);
char *find_comand_path(t_src *data);
void coll_comands(t_src *data);
void free_env(t_src *data);
void free_clin(t_src *data);
void oll_free(t_src *data);
void clin(t_src *data);
void child_coneqt(t_src *data);
void realaysing(t_src *data);
void logic(t_src *data);
int alone_child(t_src *data);
void	close_discriptor(t_src *data );
void    shell_level(t_src *data, char ** av);
void alone(t_src *data);
void exit_f(t_src *data);
int find_plase(char *s , char c);
void file_discriptor(t_src * data);
void	chek_out_file(t_src *data, int *row);
void change_fd(t_src *data);
int creat_here_doc(t_src *data);
void close_herdoq_fd(t_src *data);
void	free_token(t_src *data);
void dolar_change(t_env *env , char **key, int n);


// _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

//------src------syntax_error_1.c-------


int	when_find_tokin(t_src *data, char *str, int *i, int j);
int	pipe_last(t_src *data, char *str, int j);
void	syntax_last_nothing(t_src *data, int i, int j);



int		error_search_error2(t_src *data, char *str, int *i);
// void	get_t_cl_in_list_all(t_src *data);
#endif
