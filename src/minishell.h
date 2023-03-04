/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:55:16 by artadevo          #+#    #+#             */
/*   Updated: 2023/01/22 20:37:03 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
#include  "ft_printf.h"
# include "../libft/libft.h"
#include <sys/wait.h>


typedef enum s_type
{
	PIPE,			// |
	REDIR_OUT,   	// >
	REDIR_APPEND, 	// >>
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
    int             place;
	int				flag_p;

	struct s_env	*next;
	struct s_env	*prev;
}t_env;

typedef struct s_tokens
{
	int				len;
    char            *comand;
	char			*token;
	int				type;

	struct s_tokens	*next;
	struct s_tokens	*prev;
}t_tokens;

typedef struct s_cl_in
{
    char *id;
    char **word;
    char *oll;
    struct s_cl_in *next;
    struct s_cl_in *prev;
}       t_cl_in;

typedef struct s_src
{
	char		*line;
	int			error;
	int 		pipes_count;
	int 		(*pip)[2];
	int			ciqel;
	int 		ferst_child;
	t_tokens	*token_list;
	t_env		*env;
    t_cl_in     *cl_in;
}t_src;


typedef struct s_export
{
    int i;
    int row;
    int add;
    int string_len;
    char *key;
    char *value;
    char *addstring;
    t_env *find_key;
}           t_export;

typedef struct s_coll_comand
{
	char	**env_aray;
	int		row;
	t_env	*origin;
	char	*key_equal;
	int		i;
} t_coll_comand;

//------src-------main.c------------------


//------src-------start_pars.c------------
t_src	*ft_parser(t_src *data);

//------src------read_input.c------------
void	ft_read_l(t_src *data);
t_env	*new_node(t_env *env_list );

//------src------line_corector.c-------
char	*line_corector(char *line);
//------src------syntax_error.c-------
t_src	*syntax_error(t_src *data);
//------src------input_data.c------------
void	*start_input(t_src *data, char **env);//stex poxel em void 
t_env	*start_input_env(char **env);
//------src------str_utils.c------------
size_t	ft_strlen(const char *s);
int		ft_strchr_mod(const char *s, char c);
char	*ft_str_env_cmp(char const *s, int start, int end);
void	error_print(char *s, char *c);

void write_env_list(t_env *node, char **env); // verjum jnji
// builtins
void 	echo (t_src *data);
void 	cd(t_src *data);
void 	pwd();
t_env   *find_env(t_env *env,char *s);
void    env_f(t_src *data);
void    frik(char **s1);
void    env_fri(t_env *fri_segment);
void    delet_env(t_env *cat_segmeint);
void    unset(t_src *data);
void    export(t_src *data);
void    sort_print_env(t_env *data);
void	print_export(t_src *data);

/// logik//
int 	chek_coll_builtin(t_src *data);
char 	*find_comand_path(t_src *data);
void 	coll_comands(t_src *data);
void	 free_env(t_src *data);
void 	free_clin(t_src *data);
void 	oll_free(t_src *data);
void	 clin(t_src *data);
void 	child(t_src *data);
void 	realaysing(t_src *data);
void 	logic(t_src *data);
void	 alone_child(t_src *data);
#endif
