/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:36:45 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 20:13:00 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

bool	ft_is_valid_single(char *s)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (s[i])
	{
		if (s[i] == '=')
			sign++;
		else if (sign > 1 || s[i] == '-')
			return (false);
		else if (!ft_isalnum(s[i]) || s[i] == '_')
			return (false);
		i++;
	}
	return (true);
}

int	ft_export(t_data *data, char **args)
{
	char	**tmp;

	if (a_len(args) > 2)
		return (0);
	tmp = ft_split(args[1], '=');
	if (!tmp)
		return (ft_put_error(NULL, "Malloc failed", 1, NULL), 1);
	if (!tmp[0] || ft_isdigit(tmp[0][0]) || !ft_is_valid_single(tmp[0]))
		return (ft_put_error(NULL, "not a valid identifier", 1, NULL), 1);
	if (!tmp[1])
		return (0);
	data->envp = ft_setenv(tmp[0], tmp[1], data->envp);
	ft_freechar_array(tmp);
	return (0);
}
