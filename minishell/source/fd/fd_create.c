/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatthes <rmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:49:21 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/03 14:07:52 by rmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_get_fd(int oldfd, char *path, int flags[2], t_data *data)
{
	int	fd;

	if (oldfd > 2)
		close(oldfd);
	if (!path)
		return (-1);
	if (access(path, F_OK) == -1 && !flags[0] && ft_lstsize(data->cmds) == 1)
		ft_put_error("NoFile_NoDir", path, 0, data);
	else if (access(path, F_OK) == -1 && !flags[0])
		ft_put_error("NoFile_NoDir", path, 1, data);
	else if (!flags[0] && (access(path, R_OK) == -1)
		&& ft_lstsize(data->cmds) == 1)
		ft_put_error("Perm_Denied", path, 126, data);
	else if (flags[0] && access(path, W_OK) == -1 && access(path, F_OK) == 0
		&& ft_lstsize(data->cmds) == 1)
		ft_put_error("Perm_Denied", path, 126, data);
	if (flags[0] && flags[1])
		fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0664);
	else if (flags[0] && !flags[1])
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	else if (!flags[0] && oldfd != -1)
		fd = open(path, O_RDONLY);
	else
		fd = oldfd;
	return (fd);
}

t_cmd	*ft_out_fd_cut(t_cmd *node, char **args, int *i, t_data *data)
{
	int	flags[2];

	flags[0] = 1;
	flags[1] = 0;
	(*i)++;
	if (args[*i])
		node->out_fd = ft_get_fd(node->out_fd, args[*i], flags, data);
	if (!args[*i] || node->out_fd == -1)
	{
		*i = -1;
		if (node->out_fd != -1)
		{
			ft_putendl_fd("syntax error near unexpected token `newline'", 2);
			data->status_code = 2;
		}
		else
			data->status_code = 1;
	}
	return (node);
}

t_cmd	*ft_out_fd_add(t_cmd *node, char **args, int *i, t_data *data)
{
	int	flags[2];

	flags[0] = 1;
	flags[1] = 1;
	(*i)++;
	if (args[++(*i)])
		node->out_fd = ft_get_fd(node->out_fd, args[*i], flags, data);
	if (!args[*i] || node->out_fd == -1)
	{
		*i = -1;
		if (node->out_fd != -1)
		{
			ft_putendl_fd("syntax error near unexpected token `newline'", 2);
			data->status_code = 2;
		}
		else
			data->status_code = 1;
	}
	return (node);
}

t_cmd	*ft_in_fd_read(t_cmd *node, char **args, int *i, t_data *data)
{
	int	flags[2];

	flags[0] = 0;
	flags[1] = 0;
	(*i)++;
	if (args[*i])
		node->in_fd = ft_get_fd(node->in_fd, args[*i], flags, data);
	if (!args[*i] || node->in_fd == -1)
	{
		if (node->in_fd != -1)
		{
			ft_putendl_fd("syntax error near unexpected token `newline'", 2);
			data->status_code = 2;
		}
		if (data && data->cmds && ft_lstsize(data->cmds) != 1)
			data->status_code = 0;
		else
			(*i)--;
	}
	return (node);
}
