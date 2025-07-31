/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatthes <rmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:07:05 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/03 14:09:37 by rmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/handle.h"

int		g_exit_status;

void	ft_set_signals(t_data *data)
{
	signal(SIGINT, ft_signals_parent);
	signal(SIGQUIT, SIG_IGN);
	if (data->status_code < 0)
		data->status_code = 0;
	if (g_exit_status >= 0)
	{
		data->status_code = g_exit_status;
		g_exit_status = -1;
	}
}

void	ft_signals_parent(int signal_code)
{
	if (signal_code == SIGINT)
	{
		write(1, "\n", 1);
		g_exit_status = 130;
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_signals_child(int signal_code)
{
	if (signal_code == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		g_exit_status = 130;
	}
	else if (signal_code == SIGQUIT)
	{
		write(1, "Quit (core dumped)\n", 19);
		rl_replace_line("", 0);
		g_exit_status = 131;
		rl_on_new_line();
	}
}

void	ft_signals_heredoc(int signal_code)
{
	if (signal_code == SIGINT)
	{
		g_exit_status = 130;
		ioctl(0, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}
