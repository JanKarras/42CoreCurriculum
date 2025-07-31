/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:40:51 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 20:13:00 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

void	ft_del_index_char(char **arr, size_t i)
{
	if (arr[i] != NULL)
		free(arr[i]);
	while (arr[i])
	{
		arr[i] = arr[i + 1];
		i++;
	}
}

int	ft_unset(t_data *data, char **args)
{
	int		i;
	char	**env;

	if (a_len(args) != 2)
		return (0);
	env = data->envp;
	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], args[1], ft_strlen(args[1])) != NULL)
		{
			ft_del_index_char(data->envp, i);
			return (0);
		}
		i++;
	}
	return (0);
}
