/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:30:54 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 19:48:35 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

bool	ft_check_new_line(char *s)
{
	int	i;

	i = 2;
	if (!ft_strncmp(s, "-n", 2))
	{
		while (s[i] && s[i] == 'n')
			i++;
		if (i == (int)ft_strlen(s))
			return (true);
	}
	return (false);
}

int	ft_echo(t_cmd *cmd)
{
	int		x;
	bool	new_line_flag;

	x = 1;
	new_line_flag = false;
	if (cmd->args[1])
		new_line_flag = ft_check_new_line(cmd->args[1]);
	if (new_line_flag == true)
		x = 2;
	while (cmd->args[x])
	{
		ft_putstr_fd(cmd->args[x], 1);
		if (cmd->args[x + 1])
			ft_putchar_fd(' ', 1);
		x++;
	}
	if (new_line_flag == false)
		ft_putchar_fd('\n', 1);
	return (0);
}
