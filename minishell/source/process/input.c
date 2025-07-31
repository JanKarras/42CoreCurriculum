/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:10:20 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 20:02:34 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/process.h"

bool	ft_is_variable_bracket(char **s, int i[3], int *quotes)
{
	if (!quotes[0] && (!quotes[1] || quotes[1]) && (*s)[i[0]] == '$'
		&& (*s)[i[0] + 1] == '{' && (*s)[i[0] + 2])
		return (true);
	return (false);
}

void	ft_handle_brackets(char **s, int i[3], char *tmp[3])
{
	i[1] = i[0] + 2;
	i[2] = i[1];
	while ((*s)[i[1]] && (*s)[i[1]] != ' ' && (*s)[i[1]] != '}')
		i[1]++;
	if ((*s)[i[1]] == '}')
		tmp[2] = ft_substr(*s, i[2], i[1] - i[2]);
	else
		tmp[2] = ft_substr(*s, i[2] - 1, i[1] - i[2] + 1);
	tmp[0] = ft_substr(*s, 0, i[0]);
	tmp[1] = ft_strjoin(tmp[0], "$");
	free(tmp[0]);
	tmp[0] = ft_strjoin(tmp[1], tmp[2]);
	ft_free_all(tmp[1], tmp[2], NULL, NULL);
	tmp[1] = ft_strjoin(tmp[0], "");
	free(tmp[0]);
	tmp[0] = ft_strdup(&(*s)[i[1] + 1]);
	ft_free_all(*s, NULL, NULL, NULL);
	*s = ft_strjoin(tmp[1], tmp[0]);
	ft_free_all(tmp[0], tmp[1], NULL, NULL);
}

void	ft_del_brackets(char **s, int i[3], int quotes[2], char *tmp[3])
{
	while (*s && i[0] < (int)ft_strlen(*s) && (*s)[++i[0]])
	{
		ft_update_quotes(quotes, (*s)[i[0]]);
		if (ft_is_variable_bracket(s, i, quotes))
			ft_handle_brackets(s, i, tmp);
	}
}

void	*ft_process_input(char *input, t_data *data)
{
	char	**a;
	char	*tmp[3];
	int		i[3];
	int		quotes[2];

	i[0] = -1;
	quotes[0] = 0;
	quotes[1] = 0;
	if (!input)
		return (NULL);
	if (input && input[0] != '\0')
		add_history(input);
	if (ft_strnstr(input, "<<", ft_strlen(input)))
		ft_process_heredoc_input(&input, i, quotes, tmp);
	if (ft_strnstr(input, "${", ft_strlen(input)))
		ft_del_brackets(&input, i, quotes, tmp);
	input = ft_var_expander(input, quotes, data);
	a = split_ignore_space_in_quote(input, " ");
	if (!a)
		ft_free_exit(data, 1, "Unexpected Error");
	data = parse_nodes(a, data);
	ft_free_all(input, NULL, NULL, NULL);
	if (data && data->cmds)
		ft_lstclear(&data->cmds, ft_lst_free);
	return (data);
}
