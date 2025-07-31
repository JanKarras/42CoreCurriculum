/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:42:19 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 20:16:30 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

int	is_builtin(t_cmd *n)
{
	int	len;

	if (!n->args)
		return (0);
	if ((n->args && ft_strchr(*n->args, '/')) || (n->cmd_path
			&& ft_strchr(n->cmd_path, '/')))
		return (0);
	len = ft_strlen(*n->args);
	if (!ft_strncmp(*n->args, "pwd", len) && len == 3)
		return (1);
	if (!ft_strncmp(*n->args, "env", len) && len == 3)
		return (1);
	if (!ft_strncmp(*n->args, "cd", len) && len == 2)
		return (1);
	if (!ft_strncmp(*n->args, "export", len) && len == 6)
		return (1);
	if (!ft_strncmp(*n->args, "unset", len) && len == 5)
		return (1);
	if (!ft_strncmp(*n->args, "echo", len) && len == 4)
		return (1);
	if (!ft_strncmp(*n->args, "exit", len) && len == 4)
		return (1);
	return (0);
}

void	*ft_fork(t_data *data, t_list *cmd)
{
	int	fd[2];

	signal(SIGINT, ft_signals_child);
	signal(SIGQUIT, ft_signals_child);
	ft_get_cmd_path(data, cmd, NULL, NULL);
	if (pipe(fd) == -1)
		return (ft_put_error("DupForkPipe_Failed", NULL, 1, data));
	if (!ft_perm_call_child(data, cmd, fd))
		return (NULL);
	close(fd[1]);
	if (cmd->next && !((t_cmd *)cmd->next->content)->in_fd)
		((t_cmd *)cmd->next->content)->in_fd = fd[0];
	else
		close(fd[0]);
	if (((t_cmd *)cmd->content)->in_fd > 2)
		close(((t_cmd *)cmd->content)->in_fd);
	if (((t_cmd *)cmd->content)->out_fd > 2)
		close(((t_cmd *)cmd->content)->out_fd);
	return (NULL);
}

int	ft_process_builtin(t_data *data, char **args, int *is_exit, t_list *cmd)
{
	if (!ft_strncmp(args[0], "cd", 2))
		return (ft_cd(data, args));
	if (!ft_strncmp(args[0], "echo", 4))
		return (ft_echo((t_cmd *)cmd->content));
	if (!ft_strncmp(args[0], "pwd", 3))
		return (ft_pwd(data));
	if (!ft_strncmp(args[0], "export", 6))
		return (ft_export(data, args));
	if (!ft_strncmp(args[0], "unset", 5))
		return (ft_unset(data, args));
	if (!ft_strncmp(args[0], "exit", 4))
		ft_exit(cmd, is_exit, data);
	if (!ft_strncmp(args[0], "env", 3))
		ft_putchar_array(data->envp);
	return (0);
}

int	ft_cd_export_unset_exit(t_data *data, t_list *cmd, int *is_exit, int n)
{
	int		status_code;
	char	**args;
	size_t	len;

	(void)n;
	while (cmd)
	{
		status_code = 0;
		args = ((t_cmd *)cmd->content)->args;
		len = ft_strlen(args[0]);
		if (is_exit_cd_export_unset(args[0], len))
			status_code = ft_process_builtin(data, args, is_exit, cmd);
		else
			ft_fork(data, cmd);
		if (cmd->next)
			status_code = 0;
		cmd = cmd->next;
	}
	return (status_code);
}

void	ft_pwd_echo_env(t_data *data, t_cmd *n, int l, t_list *cmd)
{
	signal(SIGINT, ft_signals_child);
	signal(SIGQUIT, ft_signals_child);
	data->status_code = 0;
	if (!is_builtin(n) && n->args)
		execve(n->cmd_path, n->args, data->envp);
	else if (n->args && !ft_strncmp(*n->args, "pwd", l) && l == 3)
		data->status_code = ft_pwd(data);
	else if (is_builtin(n) && n->args
		&& !ft_strncmp(*n->args, "echo", l) && l == 4)
		data->status_code = ft_echo(n);
	else if (is_builtin(n) && n->args
		&& !ft_strncmp(*n->args, "env", l) && l == 3)
		ft_put_array(data->envp);
	if (cmd->next)
		data->status_code = 0;
}
