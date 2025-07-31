/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:57:51 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 20:13:00 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

t_cmd	*ft_init_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof * cmd);
	if (!cmd)
		return (ft_put_error(NULL, "Malloc failed", 1, NULL));
	cmd->args = NULL;
	cmd->cmd_path = NULL;
	cmd->in_fd = 0;
	cmd->out_fd = 1;
	return (cmd);
}

int	ft_size_for_malloc(char *s, char *set, int count)
{
	int	q[2];
	int	i;

	i = 0;
	q[0] = 0;
	q[1] = 0;
	while (s && s[i] != '\0')
	{
		count++;
		if (!ft_strchr(set, s[i]))
		{
			while ((!ft_strchr(set, s[i]) || q[0] || q[1]) && s[i] != '\0')
			{
				q[0] = (q[0] + (!q[1] && s[i] == '\'')) % 2;
				q[1] = (q[1] + (!q[0] && s[i] == '\"')) % 2;
				i++;
			}
			if (q[0] || q[1])
				return (-1);
		}
		else
			i++;
	}
	return (count);
}

char	**ft_add_to_arrayay(char **tmpstr, char *s, char *set, int i[3])
{
	int	q[2];

	q[0] = 0;
	q[1] = 0;
	while (s && s[i[0]] != '\0')
	{
		i[1] = i[0];
		if (!ft_strchr(set, s[i[0]]))
		{
			while ((!ft_strchr(set, s[i[0]]) || q[0] || q[1]) && s[i[0]])
			{
				q[0] = (q[0] + (!q[1] && s[i[0]] == '\'')) % 2;
				q[1] = (q[1] + (!q[0] && s[i[0]] == '\"')) % 2;
				i[0]++;
			}
		}
		else
			i[0]++;
		tmpstr[i[2]++] = ft_substr(s, i[1], i[0] - i[1]);
	}
	return (tmpstr);
}

char	**ft_split_pipe_redir(char const *s, char *set)
{
	char	**tmp;
	int		word_count;
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (!s)
		return (NULL);
	word_count = ft_size_for_malloc((char *)s, set, 0);
	if (word_count == -1)
		return (NULL);
	tmp = malloc((word_count + 1) * sizeof(char *));
	if (tmp == NULL)
		return (NULL);
	tmp = ft_add_to_arrayay(tmp, (char *)s, set, i);
	tmp[word_count] = NULL;
	return (tmp);
}

char	**ft_split_special_chars(char **args)
{
	char	**subsplit;
	int		i[3];

	i[2] = -1;
	while (args && args[++i[2]])
	{
		subsplit = ft_split_pipe_redir(args[i[2]], "<|>");
		ft_replace_array(&args, subsplit, i[2]);
		i[2] += a_len(subsplit) - 1;
		ft_free_array(&subsplit);
	}
	return (args);
}
