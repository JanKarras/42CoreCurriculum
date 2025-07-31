/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:16:18 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 20:14:31 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

void	ft_lst_free(void *content)
{
	t_cmd	*node;

	node = content;
	ft_free_array(&node->args);
	if (node->cmd_path)
		free(node->cmd_path);
	if (node->in_fd != 0 && node->in_fd != -1)
		close(node->in_fd);
	if (node->out_fd && node->out_fd != 1 && node->out_fd != -1)
		close(node->out_fd);
	if (node)
		free(node);
}

void	ft_free_array(char ***m)
{
	int	i;

	i = 0;
	if (!m || !*m || !**m)
		return ;
	while (m && m[0] && m[0][i])
	{
		if (m[0][i])
		{
			free(m[0][i]);
			m[0][i] = NULL;
		}
		i++;
	}
	if (m && m[0])
	{
		free(m[0]);
		*m = NULL;
	}
}

void	ft_free_all(char *s1, char *s2, char *s3, char *s4)
{
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	if (s3 != NULL)
		free(s3);
	if (s4 != NULL)
		free(s4);
}

t_list	*free_tmp_lst(t_list *cmds, char **args, char **temp)
{
	ft_lstclear(&cmds, ft_lst_free);
	ft_free_array(&temp);
	ft_free_array(&args);
	return (NULL);
}

char	*get_str(size_t i)
{
	if (i == 0)
		return (ft_strdup("PATH=/usr/bin:/bin"));
	else if (i == 1)
		return (ft_strdup("HOME=/"));
	else if (i == 2)
		return (ft_strdup("PWD=/"));
	else if (i == 3)
		return (ft_strdup("OLDPWD=/"));
	else if (i == 4)
		return (ft_strdup("SHLVL=1"));
	else if (i == 5)
		return (ft_strdup("_=./minishell"));
	else
		return (NULL);
}
