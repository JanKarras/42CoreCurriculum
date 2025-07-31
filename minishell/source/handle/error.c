/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:03:59 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 20:05:43 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/handle.h"

void	*ft_put_error(char *msg, char *cmd, int err_code, t_data *data)
{
	if (data && err_code >= 0)
		data->status_code = err_code;
	g_exit_status = err_code;
	if (msg)
	{
		if (!ft_strncmp(msg, "Unclosed_Quote", 14))
			ft_printf_fd(2, "minishell: unexpected EOF");
		else if (msg && !ft_strncmp(msg, "NoFile_NoDir", 12))
			ft_printf_fd(2, "minishell: %s: No such file or directory\n", cmd);
		else if (!ft_strncmp(msg, "Perm_Denied", 11))
			ft_printf_fd(2, "minishell: %s: Permission denied\n", cmd);
		else if (!ft_strncmp(msg, "No_Cmd", 6) && data->status_code != 2)
			ft_printf_fd(2, "minishell: %s: command not found\n", cmd);
		else if (!ft_strncmp(msg, "DupForkPipe_Failed", 18))
			ft_printf_fd(2, "minishell: %s: dup2,fork or pipe failed\n", cmd);
		else if (!ft_strncmp(msg, "Empty_Pipe", 10) && data->status_code != 2)
			ft_printf_fd(2, "minishell: %s: invalid null command\n", cmd);
		else if (!ft_strncmp(msg, "Is_Directory", 12))
			ft_printf_fd(2, "minishell: %s: Is a directory\n", cmd);
		else if (!ft_strncmp(msg, "Not_Directory", 13))
			ft_printf_fd(2, "minishell: %s: Not a directory\n", cmd);
	}
	else if (cmd && cmd[0] != '\0')
		ft_printf_fd(2, "minishell: %s\n", cmd);
	return (NULL);
}
