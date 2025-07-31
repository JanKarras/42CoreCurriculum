/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:35:20 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 19:51:18 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

void	ft_free_exit(t_data *data, int exit_code, char *msg)
{
	if (msg)
		ft_putendl_fd(msg, 2);
	if (data && data->input_text != NULL)
		free(data->input_text);
	if (data && data->envp && *data->envp)
		ft_free_array(&data->envp);
	if (data && data->cmds)
		ft_lstclear(&data->cmds, ft_lst_free);
	exit(exit_code);
}

void	ft_exit(t_list *cmd, int *is_exit, t_data *data)
{
	long long int	status[2];
	char			**args;

	args = ((t_cmd *)cmd->content)->args;
	*is_exit = !cmd->next;
	if (*is_exit)
		printf("exit\n");
	if (!args || !args[1])
		ft_free_exit(data, 0, NULL);
	status[1] = ft_atoi(args[1]);
	if (args[1][0] == '\0' || (status[1] < 0 && ft_strlen(args[1]) > 18)
		|| (status[1] == 0 && args[1][0] != '0'))
	{
		*is_exit = 1;
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(args[1], 2);
		ft_free_exit(data, (2 + status[1]) & 255, ": numeric argument req");
	}
	else if (args[2])
	{
		*is_exit = 0;
		ft_put_error(NULL, "minishell: exit: too many arguments", 1, 0);
	}
	if (*is_exit)
		ft_free_exit(data, status[1] & 255, NULL);
}
