/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:26:11 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 19:52:56 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"
# include <dirent.h>

typedef struct s_data	t_data;
typedef struct s_cmd	t_cmd;

// parse expand.c
void	ft_expand_tilde(char **str, t_data *data, int quotes[2]);
void	ft_find_var_start_end(char *var, int *j);
char	*ft_find_sub(char first, char *tmp2, t_data *data);
char	*ft_var_or_path_expand(char *str, int i, t_data *data, char *s[4]);
char	*ft_var_expander(char *str, int quotes[2], t_data *data);

// parse pathfinder.c
char	*ft_create_cmd_path(char *dir, char *cmd);
char	*ft_find_cmd(char **env_path, char *cmd, char *cmd_path);
void	ft_process_checks(t_list *cmd, char *path, t_data *data, char ***s);
DIR		*ft_cmd_checks(t_list *cmd, char ***s, char *path, t_data *data);
void	ft_get_cmd_path(t_data *data, t_list *cmd, char **s, char *path);

// parse nodes.c
int		ft_is_invalid_syntax(char *t[], int *i);
t_cmd	*ft_redir_pipe(t_cmd *t, char **a[2], int *i, t_data *data);
char	**ft_args_quotes_del(char **args);
t_list	*ft_parse_cmds(char **args, int i, t_data *data);
void	*parse_nodes(char **args, t_data *data);

// parse split_cmd.
t_cmd	*ft_init_cmd(void);
int		ft_size_for_malloc(char *s, char *set, int count);
char	**ft_add_to_arrayay(char **tmpstr, char *s, char *set, int i[3]);
char	**ft_split_pipe_redir(char const *s, char *set);
char	**ft_split_special_chars(char **args);

// parse split_spaces.c
int		ft_count_tokens(const char *s, char *c, int i[2]);
char	**ft_add_to_array(char **tmpstr, char *s, char *set, int i[3]);
char	**split_ignore_space_in_quote(char *s, char *set);

// parse del_quotes.c
int		ft_check_quotes(char const *s1);
char	*ft_del_quotes(char const *s1, int squote, int dquote);

#endif
