/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:12:03 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 20:01:46 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_init(t_data *data, char **envp, char **argv, int argc)
{
	(void)argc;
	(void)argv;
	data->cmds = NULL;
	data->input_text = NULL;
	g_exit_status = 0;
	data->status_code = 0;
	data->pid_of_lst_cmd = 0;
	if (!envp || !(*envp))
		ft_free_exit(data, 1, "No envp");
	data->envp = ft_dup_array(envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*prompt;
	char	*path;

	ft_init(&data, envp, argv, argc);
	while (1)
	{
		ft_set_signals(&data);
		path = ft_getenv("PWD", data.envp);
		if (path == NULL)
			path = ft_strdup("/");
		prompt = ft_strjoin(path, "> ");
		free(path);
		if (prompt == NULL)
			ft_free_exit(&data, 1, "get prompt error");
		data.input_text = readline(prompt);
		free(prompt);
		if (!ft_process_input(data.input_text, &data))
			break ;
	}
	ft_free_exit(&data, data.status_code, NULL);
}
