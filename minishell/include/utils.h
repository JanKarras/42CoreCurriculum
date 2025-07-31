/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:28:37 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/09 11:43:12 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

typedef struct s_data	t_data;
typedef struct s_cmd	t_cmd;

// utils array.c
void	ft_put_array(char **m);
int		a_len(char **m);
char	**ft_dup_array(char **arr_ptr);
char	**ft_insert_array(char **in, char *newstr);
char	**ft_replace_array(char ***big, char **small, int n);

// utils free.c
void	ft_lst_free(void *content);
void	ft_free_array(char ***m);
void	ft_free_all(char *s1, char *s2, char *s3, char *s4);
t_list	*free_tmp_lst(t_list *cmds, char **args, char **temp);
char	*get_str(size_t i);

// utils utils.c
int		ft_char_count(char *s, char c);
int		ft_index_strchrs(const char *s, char *set);
int		ft_index_strchr(const char *s, int c);
char	*ft_join_3_strings(char *s1, char *s2, char *s3);
int		ft_printf_fd(int fd, char *format, ...);

//utils wait.c
void	wait_for_all_childs(t_data *data, int *status);
bool	check_syntax_help(char *t[], int *i);

#endif
