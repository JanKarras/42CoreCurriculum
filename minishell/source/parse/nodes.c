/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:56:03 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/09 11:44:00 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

int	ft_is_invalid_syntax(char *t[], int *i)
{
	int	syntax_error;

	syntax_error = 0;
	if (t[0][0] == '|')
		syntax_error = 1;
	else if ((t[*i][0] == '>' && t[*i + 1] == NULL) ||
		(t[*i][0] == '>' && t[*i + 1] && t[*i + 1][0] == '>'
			&& t[*i + 2] == NULL))
		syntax_error = 1;
	else if (t[*i][0] == '>' && t[*i + 1] && t[*i + 1][0] == '>' &&
			t[*i + 2] && t[*i + 2][0] == '>')
		syntax_error = 1;
	else
		syntax_error = check_syntax_help(t, i);
	if (syntax_error)
		*i = -1;
	return (syntax_error);
}

t_cmd	*ft_redir_pipe(t_cmd *t, char **a[2], int *i, t_data *data)
{
	if (*i >= 0 && a && a[0] && a[0][*i])
	{
		if (ft_is_invalid_syntax(a[0], i))
			return (ft_put_error(0, "syntax error near token", 2, data), t);
		else if (a[0][*i][0] == '>' && a[0][*i + 1] && a[0][*i + 1][0] == '>'
			&& g_exit_status != 130)
			t = ft_out_fd_add(t, a[1], i, data);
		else if (a[0][*i][0] == '>' && g_exit_status != 130)
			t = ft_out_fd_cut(t, a[1], i, data);
		else if (a[0][*i][0] == '<' && a[0][*i + 1] && a[0][*i + 1][0] == '<')
			t = ft_fd_heredoc(t, a[1], i, data);
		else if (a[0][*i][0] == '<')
			t = ft_in_fd_read(t, a[1], i, data);
		else if (a[0][*i][0] != '|')
			t->args = ft_insert_array(t->args, a[1][*i]);
		else
		{
			ft_put_error("Empty_Pipe", NULL, 2, data);
			*i = -1;
		}
		return (t);
	}
	*i = -1;
	return (ft_put_error("Empty_Pipe", NULL, 2, data), t);
}

char	**ft_args_quotes_del(char **args)
{
	char	**temp;
	char	*tmpstr;
	int		j;

	j = -1;
	temp = ft_dup_array(args);
	while (temp && temp[++j])
	{
		tmpstr = ft_del_quotes(temp[j], 0, 0);
		free(temp[j]);
		temp[j] = tmpstr;
	}
	return (temp);
}

t_list	*ft_parse_cmds(char **args, int i, t_data *data)
{
	t_list	*cmds[2];
	char	**temp[2];
	t_cmd	*tmp;

	cmds[0] = NULL;
	temp[1] = ft_args_quotes_del(args);
	while (args[++i])
	{
		cmds[1] = ft_lstlast(cmds[0]);
		if (i == 0 || (args[i][0] == '|' && args[i + 1] && args[i + 1][0]))
		{
			i += args[i][0] == '|';
			ft_lstadd_back(&cmds[0], ft_lstnew(ft_init_cmd()));
			cmds[1] = ft_lstlast(cmds[0]);
		}
		temp[0] = args;
		tmp = cmds[1]->content;
		cmds[1]->content = ft_redir_pipe(tmp, temp, &i, data);
		if (i < 0)
			return (free_tmp_lst(cmds[0], args, temp[1]));
	}
	ft_free_array(&temp[1]);
	ft_free_array(&args);
	return (cmds[0]);
}

void	*parse_nodes(char **args, t_data *data)
{
	int	is_exit;
	int	status;
	int	tmp[2];

	is_exit = 0;
	status = 0;
	tmp[0] = -1;
	tmp[1] = -1;
	data->cmds = ft_parse_cmds(ft_split_special_chars(args), -1, data);
	if (!data->cmds)
		return (data);
	if (ft_lstsize(data->cmds) == 1 && ((t_cmd *)(data->cmds->content))->args
		&& a_len(((t_cmd *)(data->cmds->content))->args))
		ft_setenv("_", ((t_cmd *)(data->cmds->content))->args[a_len(((t_cmd *)
					(data->cmds->content))->args) - 1], data->envp);
	ft_exec_cmd_wait(data, status, tmp, &is_exit);
	if (is_exit)
		ft_free_exit(data, data->status_code, NULL);
	if (data->cmds && is_exit)
	{
		ft_lstclear(&data->cmds, ft_lst_free);
		return (NULL);
	}
	return (data);
}
