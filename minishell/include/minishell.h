/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:13:51 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 18:45:59 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "builtins.h"
# include "handle.h"
# include "parse.h"
# include "utils.h"
# include "process.h"
# include "execute.h"
# include "heredoc.h"

# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdarg.h>

extern int	g_exit_status;

typedef struct s_cmd
{
	char	**args;
	char	*cmd_path;
	int		in_fd;
	int		out_fd;
	pid_t	id;
}			t_cmd;

typedef struct s_data
{
	t_list	*cmds;
	char	**envp;
	char	*input_text;
	int		status_code;
	pid_t	pid_of_lst_cmd;
}			t_data;

// source main.c
//int		ft_allocate_env(t_data *data);
//void	ft_init_reset_source(t_data *data, char **envp);
bool	set_default_envp(t_data *data);
bool	initialize_env(t_data *data, char **envp);
void	update_env_vars(t_data *data);
void	ft_init(t_data *data, char **envp, char **argv, int argc);
int		main(int argc, char **argv, char **envp);

// source fd_create.c
int		ft_get_fd(int oldfd, char *path, int flags[2], t_data *data);
t_cmd	*ft_out_fd_cut(t_cmd *node, char **args, int *i, t_data *data);
t_cmd	*ft_out_fd_add(t_cmd *node, char **args, int *i, t_data *data);
t_cmd	*ft_in_fd_read(t_cmd *node, char **args, int *i, t_data *data);

#endif
