/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:53:36 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 20:13:00 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

char	*ft_create_cmd_path(char *dir, char *cmd)
{
	char	*temp_dir;
	char	*temp;
	char	*cmd_path;

	temp_dir = ft_strdup(dir);
	if (!temp_dir)
		return (NULL);
	temp = ft_strjoin(temp_dir, "/");
	free(temp_dir);
	if (!temp)
		return (NULL);
	cmd_path = ft_strjoin(temp, cmd);
	free(temp);
	if (!cmd_path)
		return (NULL);
	return (cmd_path);
}

char	*ft_find_cmd(char **env_path, char *cmd, char *cmd_path)
{
	int		i;
	char	*temp;

	i = -1;
	while (env_path && env_path[++i])
	{
		ft_free_all(cmd_path, NULL, NULL, NULL);
		cmd_path = NULL;
		temp = ft_create_cmd_path(env_path[i], cmd);
		if (!temp)
			return (NULL);
		cmd_path = ft_strdup(temp);
		free(temp);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, F_OK) == 0)
			break ;
	}
	if ((!env_path || !env_path[i]) && cmd_path)
	{
		free(cmd_path);
		return (NULL);
	}
	return (cmd_path);
}

void	ft_process_checks(t_list *cmd, char *path, t_data *data, char ***s)
{
	t_cmd	*n;

	n = cmd->content;
	if (!is_builtin(n) && n->args && !ft_strchr("/.~", n->args[0][0]))
	{
		*s = ft_split(path, ':');
		n->cmd_path = ft_find_cmd(*s, *n->args, n->cmd_path);
		if ((!n->cmd_path || !n->args[0]) && n->args[0][0] && !cmd->next
			&& n->in_fd != -1)
			ft_put_error("No_Cmd", n->args[0], 127, data);
		else if ((!n->cmd_path || !n->args[0]) && n->args[0][0]
			&& n->in_fd != -1)
			ft_put_error("No_Cmd", n->args[0], 0, data);
	}
}

DIR	*ft_cmd_checks(t_list *cmd, char ***s, char *path, t_data *data)
{
	t_cmd	*n;
	DIR		*dir;

	n = cmd->content;
	dir = NULL;
	if (n && n->args)
		dir = opendir(n->args[0]);
	if (n && n->args && ft_strchr(*n->args, '/') && !dir)
	{
		*s = ft_split(*n->args, '/');
		n->cmd_path = ft_strdup(*n->args);
		free(n->args[0]);
		n->args[0] = ft_strdup((*s)[a_len(*s) - 1]);
	}
	else if (!dir)
		ft_process_checks(cmd, path, data, s);
	ft_free_all(path, NULL, NULL, NULL);
	return (dir);
}

void	ft_get_cmd_path(t_data *data, t_list *cmd, char **s, char *path)
{
	t_cmd	*n;
	DIR		*dir;

	n = cmd->content;
	path = ft_getenv("PATH", data->envp);
	if (!path || !*path)
		path = ft_strdup("/");
	dir = ft_cmd_checks(cmd, &s, path, data);
	if (!is_builtin(n) && n && n->args && dir && (n->args[0][0]
		&& !ft_strchr("/.~", n->args[0][0])))
		ft_put_error(NULL, "command not found", 127, data);
	else if (!is_builtin(n) && n && n->args && dir && n->args[0][0]
			&& (ft_strchr("/.~", n->args[0][0])))
		ft_put_error("Is_Directory", *n->args, 126, data);
	else if (!is_builtin(n) && n && n->cmd_path
		&& access(n->cmd_path, F_OK) == -1)
		ft_put_error("NoFile_NoDir", n->cmd_path, 127, data);
	else if (!is_builtin(n) && n && n->cmd_path
		&& access(n->cmd_path, X_OK) == -1)
		ft_put_error("Perm_Denied", n->cmd_path, 126, data);
	if (dir)
		closedir(dir);
	if (cmd->next != NULL)
		data->status_code = 0;
	ft_free_array(&s);
}
