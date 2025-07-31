/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:27:50 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 19:55:09 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "minishell.h"

typedef struct s_data	t_data;
typedef struct s_cmd	t_cmd;

// process input.c
void	ft_del_brackets(char **s, int i[3], int quotes[2], char *tmp[3]);
void	ft_process_heredoc_input(char **s, int i[3], int q[2], char *tmp[3]);
void	*ft_process_input(char *input, t_data *data);

#endif
