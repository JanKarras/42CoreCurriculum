/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:30:04 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 20:17:16 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "minishell.h"

typedef struct s_data	t_data;
typedef struct s_cmd	t_cmd;

// execute execute.c
void	ft_exec_cmd_wait(t_data *data, int status, int tmp[2], int *is_exit);
void	*ft_dup_fds(t_list *cmd, int fd[2]);
void	*ft_exec_child(t_data *data, t_list *cmd, int fd[2]);
void	ft_create_fork(t_data *data, t_list *cmd, int fd[2]);
void	*ft_perm_call_child(t_data *data, t_list *cmd, int fd[2]);
bool	is_exit_cd_export_unset(char *cmd, size_t len);
bool	is_echo_pwd_env(char *cmd, size_t len);

#endif
