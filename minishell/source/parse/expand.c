/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:51:28 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 20:07:23 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

char	*ft_expand_status(char *str, int *i, t_data *data, int *quotes)
{
	char	*tmp[3];

	tmp[0] = ft_substr(str, 0, *i);
	if (g_exit_status > 0)
	{
		data->status_code = g_exit_status;
		g_exit_status = 0;
	}
	tmp[1] = ft_itoa(data->status_code);
	tmp[2] = ft_substr(str, *i + 2, ft_strlen(&str[*i + 2]));
	tmp[0] = ft_strjoin(tmp[0], tmp[1]);
	tmp[0] = ft_strjoin(tmp[0], tmp[2]);
	ft_free_all(tmp[1], tmp[2], str, NULL);
	*i = -1;
	quotes[1] = 0;
	quotes[0] = 0;
	return (tmp[0]);
}

char	*ft_expand_var(char *str, int *i, t_data *data, int *quotes)
{
	char	*tmp[4];
	int		j;

	tmp[0] = ft_substr(str, 0, *i);
	*i = *i + 1;
	j = *i;
	while (ft_isalnum(str[j]) || str[j] == '_')
		j++;
	tmp[1] = ft_substr(&str[j], 0, ft_strlen(&str[j]));
	tmp[2] = ft_substr(&str[*i], 0, j - *i);
	tmp[3] = ft_getenv(tmp[2], data->envp);
	if (tmp[3] == NULL)
		tmp[3] = ft_strdup("");
	tmp[0] = ft_strjoin(tmp[0], tmp[3]);
	tmp[0] = ft_strjoin(tmp[0], tmp[1]);
	ft_free_all(tmp[1], tmp[2], tmp[3], str);
	*i = -1;
	quotes[1] = 0;
	quotes[0] = 0;
	return (tmp[0]);
}

char	*ft_var_expander(char *str, int quotes[2], t_data *data)
{
	int		i;

	i = -1;
	quotes[0] = 0;
	quotes[1] = 0;
	while (str && str[++i] && i < (int)ft_strlen(str))
	{
		ft_update_quotes(quotes, str[i]);
		if (str[i] == '$' && quotes[0] == 0)
		{
			if (ft_isalnum(str[i + 1]) || str[i + 1] == '_')
				str = ft_expand_var(str, &i, data, quotes);
			else if (str[i + 1] == '?')
				str = ft_expand_status(str, &i, data, quotes);
		}
	}
	return (str);
}
