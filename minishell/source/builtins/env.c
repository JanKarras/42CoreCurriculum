/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:31:59 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 20:15:29 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

int	ft_get_var_index(char *var, char **envp)
{
	int	i;
	int	n;
	int	n2;

	i = 0;
	n = ft_strlen(var);
	while (envp && envp[i])
	{
		n2 = n;
		if (n2 < ft_index_strchr(envp[i], '='))
			n2 = ft_index_strchr(envp[i], '=');
		if (!ft_strncmp(envp[i], var, n2))
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_getenv(char *var, char **envp)
{
	int			var_index;
	const char	*env_var;
	const char	*value_start;

	if (var[0] == 0)
		return (ft_strdup("'$'"));
	var_index = ft_get_var_index(var, envp);
	if (var_index == -1)
		return (NULL);
	env_var = envp[var_index];
	value_start = ft_strchr(env_var, '=');
	if (value_start)
	{
		value_start++;
		return (ft_strdup(value_start));
	}
	return (NULL);
}

char	**ft_setenv(char *var, char *value, char **envp)
{
	int		index;
	char	*tmpstr[2];

	index = ft_get_var_index(var, envp);
	if (index != -1)
	{
		tmpstr[0] = ft_strjoin(var, "=");
		if (tmpstr[0])
		{
			free(envp[index]);
			envp[index] = ft_strjoin(tmpstr[0], value);
			free(tmpstr[0]);
		}
	}
	else
	{
		tmpstr[0] = ft_strjoin(var, "=");
		if (tmpstr[0])
		{
			tmpstr[1] = ft_strjoin(tmpstr[0], value);
			envp = ft_insert_array(envp, tmpstr[1]);
			ft_free_all(tmpstr[0], tmpstr[1], NULL, NULL);
		}
	}
	return (envp);
}

void	ft_handle_env_vars(char *str, int *i, int fd[2], t_data *data)
{
	int		j;
	char	*tmp;
	char	*tmp2;

	j = *i + 1;
	while (str[j])
	{
		if (!ft_isalnum(str[j]) || str[j] == ' ' || str[j] == '\n'
			|| str[j] == '\t' || str[j] == '$' || str[j] == '\"'
			|| str[j] == '\'' || str[j] == '<')
			break ;
		j++;
	}
	tmp = ft_substr(str, *i + 1, j - *i - 1);
	tmp2 = ft_getenv(tmp, data->envp);
	write(fd[1], tmp2, ft_strlen(tmp2));
	ft_free_all(tmp, tmp2, NULL, NULL);
	*i = j - 1;
}
