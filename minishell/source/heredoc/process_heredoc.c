/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:26:02 by jkarras           #+#    #+#             */
/*   Updated: 2024/09/08 20:01:27 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	ft_check_synax_error(char **s, int i)
{
	char	*msg;

	msg = ft_strdup("syntax error near unexpected token `<'");
	if ((*s)[i] && (*s)[i] == '<' && (*s)[i + 1] && (*s)[i + 1] == '<')
	{
		if (!(*s)[i + 2] || (*s)[i + 2] == '\0')
		{
			ft_put_error(msg, NULL, 2, NULL);
			return (free(msg), true);
		}
		if ((*s)[i + 2] == '<')
		{
			ft_put_error(msg, NULL, 2, NULL);
			return (free(msg), true);
		}
	}
	free(msg);
	return (false);
}

bool	ft_process_heredoc_marker(char **s, int i[3], char *tmp[3])
{
	i[1] = i[0] + 2;
	while ((*s)[i[1]] && (ft_strchr(" \\t", (*s)[i[1]])))
		i[1]++;
	i[2] = i[1];
	while ((*s)[i[1]] && (*s)[i[1]] != ' ' && (*s)[i[1]] != '\t')
		i[1]++;
	tmp[2] = ft_substr(*s, i[2], i[1] - i[2]);
	tmp[0] = ft_substr(*s, 0, i[0]);
	tmp[1] = ft_strjoin(tmp[0], "<<'");
	free(tmp[0]);
	tmp[0] = ft_strjoin(tmp[1], tmp[2]);
	ft_free_all(tmp[1], tmp[2], NULL, NULL);
	tmp[1] = ft_strjoin(tmp[0], "'");
	free(tmp[0]);
	tmp[0] = ft_strdup(&(*s)[i[1]]);
	ft_free_all(*s, NULL, NULL, NULL);
	*s = ft_strjoin(tmp[1], tmp[0]);
	ft_free_all(tmp[0], tmp[1], NULL, NULL);
	return (false);
}

void	ft_update_quotes(int *quotes, char c)
{
	quotes[0] = (quotes[0] + (!quotes[1] && c == '\'')) % 2;
	quotes[1] = (quotes[1] + (!quotes[0] && c == '\"')) % 2;
}

void	ft_process_heredoc_input(char **s, int i[3], int q[2], char *tmp[3])
{
	while (*s && i[0] < (int)ft_strlen(*s) && (*s)[++i[0]])
	{
		ft_update_quotes(q, (*s)[i[0]]);
		if (!q[0] && !q[1] && (*s)[i[0]] == '<' && (*s)[i[0] + 1] == '<')
		{
			if (ft_check_synax_error(s, i[0]))
				return ;
			if (ft_process_heredoc_marker(s, i, tmp))
				return ;
		}
	}
}
