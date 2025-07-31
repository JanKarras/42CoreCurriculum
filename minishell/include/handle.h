/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:25:06 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 19:53:04 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_H
# define HANDLE_H

# include "minishell.h"

typedef struct s_data	t_data;
typedef struct s_cmd	t_cmd;

// handle error.c
void	*ft_put_error(char *err_msg, char *cmd, int err_code, t_data *data);

// handle signal.c
void	ft_set_signals(t_data *data);
void	ft_signals_parent(int signal_code);
void	ft_signals_child(int signal_code);
void	ft_signals_heredoc(int signal_code);

#endif
