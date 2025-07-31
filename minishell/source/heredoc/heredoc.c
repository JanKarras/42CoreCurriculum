/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:08:33 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 19:57:35 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/handle.h"

char	*ft_get_heredoc_str(char *str[3], char *lim, t_data *data)
{
	data->status_code = 0;
	g_exit_status = 0;
	while (data->status_code != 130 && g_exit_status != 130)
	{
		if (!str[1])
			str[1] = ft_strdup("");
		if (!str[0])
			str[0] = ft_strdup("");
		str[2] = str[1];
		str[1] = ft_strjoin(str[1], str[0]);
		ft_free_all(str[0], str[2], NULL, NULL);
		str[0] = readline("> ");
		if (!str[0])
		{
			printf("%s (wanted `%s\')\n", "minishell: warning: eof", lim);
			break ;
		}
		str[2] = str[0];
		if (str[2] && str[2][0] && !ft_strncmp(str[2], lim, ft_strlen(str[2]))
			&& ft_strlen(str[2]) == ft_strlen(lim))
			break ;
		str[0] = ft_strjoin(str[0], "\n");
		free(str[2]);
	}
	return (ft_free_all(str[0], NULL, NULL, NULL), str[1]);
}

void	ft_process_heredoc(char *str[1], int fd[2], t_data *data, int expand)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[1] && str[1][i])
	{
		j = i + 1;
		if (str[1][i] && str[1][i] == '$' && str[1][j] && ft_isalnum(str[1][j])
			&& expand)
			ft_handle_env_vars(str[1], &i, fd, data);
		else if (str[1][i])
			write(fd[1], &str[1][i], 1);
		i++;
	}
}

char	*ft_del_all_quotes(char *str)
{
	size_t	len;
	size_t	result_len;
	size_t	i;
	char	*result;
	size_t	j;

	len = ft_strlen(str);
	result_len = 0;
	i = -1;
	while (++i < len)
		if (str[i] != '\'' && str[i] != '\"')
			result_len++;
	result = (char *)malloc(result_len + 1);
	if (!result)
	{
		return (NULL);
	}
	j = 0;
	i = -1;
	while (++i < len)
		if (str[i] != '\'' && str[i] != '\"')
			result[j++] = str[i];
	result[j] = '\0';
	return (result);
}

int	ft_read_heredoc(char *str[3], char *tmpstr[2], t_data *data)
{
	int	fd[2];
	int	expand;

	expand = 1;
	signal(SIGINT, ft_signals_heredoc);
	signal(SIGQUIT, SIG_IGN);
	if (pipe(fd) == -1)
		return (ft_put_error("DupForkPipe_Failed", NULL, 1, data), -1);
	if (ft_index_strchrs(tmpstr[0], "\"'") != -1)
		expand = 0;
	tmpstr[0] = ft_del_all_quotes(tmpstr[0]);
	str[1] = ft_get_heredoc_str(str, tmpstr[0], data);
	ft_process_heredoc(str, fd, data, expand);
	ft_free_all(str[1], tmpstr[0], NULL, NULL);
	if (fd[1] != -1)
		close(fd[1]);
	if (data->status_code == 130)
	{
		if (fd[0] != -1)
			close(fd[0]);
		return (-1);
	}
	return (fd[0]);
}

t_cmd	*ft_fd_heredoc(t_cmd *node, char **args, int *i, t_data *data)
{
	char	*tmpstr[2];
	char	*str[3];

	str[0] = NULL;
	str[1] = NULL;
	str[2] = NULL;
	tmpstr[1] = "minishell: warning: here-document delimited by end-of-file";
	(*i)++;
	if (args[++(*i)])
	{
		tmpstr[0] = args[*i];
		node->in_fd = ft_read_heredoc(str, tmpstr, data);
	}
	if (!args[*i] || node->in_fd == -1)
	{
		*i = -1;
		if (node->in_fd != -1)
		{
			ft_putendl_fd("syntax error near unexpected token `newline'", 2);
			data->status_code = 2;
		}
	}
	return (node);
}
