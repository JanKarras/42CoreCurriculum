/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_wait.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:03:19 by jkarras           #+#    #+#             */
/*   Updated: 2024/09/09 11:45:05 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	wait_for_all_childs(t_data *data, int *status)
{
	t_list	*list;
	t_cmd	*node;

	list = data->cmds;
	while (list)
	{
		node = (t_cmd *)list->content;
		if (list->next)
		{
			waitpid(node->id, status, 0);
		}
		else
		{
			waitpid(data->pid_of_lst_cmd, status, 0);
			data->pid_of_lst_cmd = 0;
		}
		list = list->next;
	}
}

bool	is_exit_cd_export_unset(char *cmd, size_t len)
{
	if (ft_strncmp(cmd, "exit", 4) == 0 && len == 4)
		return (true);
	if (ft_strncmp(cmd, "cd", 2) == 0 && len == 2)
		return (true);
	if (ft_strncmp(cmd, "export", 6) == 0 && len == 6)
		return (true);
	if (ft_strncmp(cmd, "unset", 5) == 0 && len == 5)
		return (true);
	return (false);
}

bool	is_echo_pwd_env(char *cmd, size_t len)
{
	if (ft_strncmp(cmd, "exit", 4) == 0 && len == 4)
		return (true);
	if (ft_strncmp(cmd, "cd", 2) == 0 && len == 2)
		return (true);
	if (ft_strncmp(cmd, "export", 6) == 0 && len == 6)
		return (true);
	if (ft_strncmp(cmd, "unset", 5) == 0 && len == 5)
		return (true);
	if (ft_strncmp(cmd, "echo", 4) == 0 && len == 4)
		return (true);
	if (ft_strncmp(cmd, "pwd", 3) == 0 && len == 3)
		return (true);
	if (ft_strncmp(cmd, "env", 3) == 0 && len == 3)
		return (true);
	return (false);
}

bool	check_syntax_help(char *t[], int *i)
{
	return (((t[*i] && t[*i][0] == '<'
			&& ((t[*i + 1] == NULL) || (t[*i + 1][0]
				&& t[*i + 1][0] == '<' && ((t[*i + 2]
					&& t[*i + 2] == NULL) || (t[*i + 2]
					&& t[*i + 2][0] == '<'))))) || ((t[*i][0]
					&& t[*i][0] == '>' && t[*i + 1] == NULL) || (t[*i][0] == '>'
					&& t[*i + 1] && t[*i + 1][0]
					&& t[*i + 1][0] == '|') || (t[*i][0]
					&& t[*i][0] == '<' && t[*i + 1]
					&& t[*i + 1][0] == '|') || (t[*i][0]
					&& t[*i][0] == '|' && t[*i + 1]
					&& t[*i + 1][0] == '|'))));
}
