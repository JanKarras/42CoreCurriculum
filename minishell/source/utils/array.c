/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:14:10 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 20:13:00 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

void	ft_put_array(char **m)
{
	int	i;

	i = 0;
	while (m && m[i])
	{
		ft_putendl_fd(m[i], 1);
		i++;
	}
}

int	a_len(char **m)
{
	int	i;

	i = 0;
	if (!m)
		return (i);
	while (m && m[i])
		i++;
	return (i);
}

char	**ft_dup_array(char **arr_ptr)
{
	char	**arr_copy;
	int		size;
	int		i;

	i = 0;
	size = a_len(arr_ptr);
	arr_copy = malloc(sizeof(char *) * (size + 1));
	if (!arr_copy)
		return (NULL);
	while (arr_ptr[i])
	{
		arr_copy[i] = ft_strdup(arr_ptr[i]);
		if (!arr_copy[i])
			return (ft_free_array(&arr_copy), NULL);
		i++;
	}
	arr_copy[i] = NULL;
	return (arr_copy);
}

char	**ft_insert_array(char **in, char *newstr)
{
	char	**out;
	int		len;
	int		i;

	i = -1;
	out = NULL;
	if (!newstr)
		return (in);
	len = a_len(in);
	out = ft_calloc(1, sizeof(char *) * (len + 2));
	if (!out)
		return (ft_put_error(NULL, "Malloc failed", 1, NULL));
	out[len + 1] = NULL;
	while (++i < len)
	{
		out[i] = ft_strdup(in[i]);
		if (!out[i])
		{
			ft_free_array(&in);
			ft_free_array(&out);
		}
	}
	out[i] = ft_strdup(newstr);
	ft_free_array(&in);
	return (out);
}

char	**ft_replace_array(char ***big, char **small, int n)
{
	char	**tmpstr;
	int		i[3];

	i[0] = -1;
	i[1] = -1;
	i[2] = -1;
	if (!big || !*big || n < 0 || n >= a_len(*big))
		return (NULL);
	tmpstr = ft_calloc(a_len(*big) + a_len(small), sizeof(char *));
	if (!tmpstr)
		return (ft_put_error(NULL, "Malloc failed", 1, NULL));
	while (tmpstr && big[0][++i[0]])
	{
		if (i[0] != n)
			tmpstr[++i[2]] = ft_strdup(big[0][i[0]]);
		else
		{
			while (small && small[++i[1]])
				tmpstr[++i[2]] = ft_strdup(small[i[1]]);
		}
	}
	ft_free_array(big);
	*big = tmpstr;
	return (*big);
}
