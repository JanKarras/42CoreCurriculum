/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:27:20 by jkarras           #+#    #+#             */
/*   Updated: 2024/09/08 19:52:40 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "minishell.h"

typedef struct s_data	t_data;
typedef struct s_cmd	t_cmd;

// handle heredoc.c
char	*ft_get_heredoc_str(char *str[3], char *lim, t_data *data);
void	ft_process_heredoc(char *str[1], int fd[2], t_data *data, int expand);
char	*ft_del_all_quotes(char *str);
int		ft_read_heredoc(char *str[3], char *tmpstr[2], t_data *data);
t_cmd	*ft_fd_heredoc(t_cmd *node, char **args, int *i, t_data *data);
void	ft_update_quotes(int *quotes, char c);

#endif
