/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:45:54 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 20:03:15 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execute.h"

void	ft_exec_cmd_wait(t_data *data, int status, int tmp[2], int *is_exit)
{
	tmp[1] = ft_cd_export_unset_exit(data, data->cmds, is_exit, 0);
	if (ft_lstsize(data->cmds) == 1)
		data->status_code = tmp[1];
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (data && data->pid_of_lst_cmd != 0)
		wait_for_all_childs(data, &status);
	waitpid(-1, NULL, 0);
	if (WIFSIGNALED(status))
		ft_signals_child(WTERMSIG(status));
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 127 && !tmp[1])
			data->status_code = WEXITSTATUS(status);
		else if (!tmp[1])
			data->status_code = WEXITSTATUS(status);
		else if (status && WEXITSTATUS(status))
			data->status_code = WEXITSTATUS(status);
	}
	else if (WIFSIGNALED(status) && status != 13)
		data->status_code = 128 + WTERMSIG(status);
	data->status_code = data->status_code & 255;
}

void	*ft_dup_fds(t_list *cmd, int fd[2])
{
	t_cmd	*node;

	node = cmd->content;
	if (node->in_fd != 0)
	{
		if (dup2(node->in_fd, 0) == -1)
			return (ft_put_error("DupForkPipe_Failed", NULL, 1, NULL));
		if (node->in_fd != -1)
			close(node->in_fd);
	}
	if (node->out_fd != 1)
	{
		if (dup2(node->out_fd, 1) == -1)
			return (ft_put_error("DupForkPipe_Failed", NULL, 1, NULL));
		if (node->out_fd != -1)
			close(node->out_fd);
	}
	else if (cmd->next && dup2(fd[1], 1) == -1)
		return (ft_put_error("DupForkPipe_Failed", NULL, 1, NULL));
	if (fd[1] != -1)
		close(fd[1]);
	return (NULL);
}

void	*ft_exec_child(t_data *data, t_list *cmd, int fd[2])
{
	t_cmd	*n;
	int		l;

	n = cmd->content;
	l = 0;
	if (n->args)
		l = ft_strlen(*n->args);
	ft_dup_fds(cmd, fd);
	close(fd[0]);
	ft_pwd_echo_env(data, n, l, cmd);
	if (cmd->next != NULL)
		data->status_code = 0;
	l = data->status_code;
	if (data && data->cmds)
		ft_lstclear(&data->cmds, ft_lst_free);
	if (data && data->envp)
		ft_free_array(&data->envp);
	exit(l);
}

void	ft_create_fork(t_data *data, t_list *cmd, int fd[2])
{
	pid_t	pid;
	t_cmd	*node;

	signal(SIGINT, ft_signals_child);
	signal(SIGQUIT, ft_signals_child);
	node = (t_cmd *)cmd->content;
	pid = fork();
	if (pid > 0)
	{
		if (cmd->next)
			node->id = pid;
		else
			data->pid_of_lst_cmd = pid;
	}
	if (pid < 0)
	{
		if (fd[0] != -1)
			close(fd[0]);
		if (fd[1] != -1)
			close(fd[1]);
		ft_put_error("DupForkPipe_Failed", NULL, 1, data);
	}
	else if (!pid)
		ft_exec_child(data, cmd, fd);
}

void	*ft_perm_call_child(t_data *data, t_list *cmd, int fd[2])
{
	t_cmd	*n;
	DIR		*dir;

	n = cmd->content;
	dir = NULL;
	if (n->args)
		dir = opendir(*n->args);
	if (n->in_fd == -1 || n->out_fd == -1)
		return (NULL);
	if ((n->cmd_path && access(n->cmd_path, X_OK) == 0) || is_builtin(n))
		ft_create_fork(data, cmd, fd);
	else if (!is_builtin(n) && ((n->cmd_path && !access(n->cmd_path, F_OK))
			|| dir))
		data->status_code = 126;
	else if (!is_builtin(n) && n->args)
		data->status_code = 127;
	if (dir)
		closedir(dir);
	return ("");
}
