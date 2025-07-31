/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:00:08 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 17:38:30 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

int	ft_count_tokens(const char *s, char *c, int i[2])
{
	int	q[2];

	q[0] = 0;
	q[1] = 0;
	while (s[i[0]] != '\0')
	{
		if (!ft_strchr(c, s[i[0]]))
		{
			i[1]++;
			while (s[i[0]] && (!ft_strchr(c, s[i[0]]) || q[0]))
			{
				if (!q[1] && s[i[0]] && (s[i[0]] == '\"' || s[i[0]] == '\''))
					q[1] = s[i[0]];
				q[0] = (q[0] + (s[i[0]] == q[1])) % 2;
				q[1] *= q[0] != 0;
				i[0]++;
			}
			if (q[0])
				return (-1);
		}
		else
			i[0]++;
	}
	return (i[1]);
}

char	**ft_add_to_array(char **tmpstr, char *s, char *set, int i[3])
{
	int	s_len;
	int	q[2];

	q[0] = 0;
	q[1] = 0;
	s_len = ft_strlen(s);
	while (s[i[0]])
	{
		while (s[i[0]] && ft_strchr(set, s[i[0]]) && s[i[0]] != '\0')
			i[0]++;
		i[1] = i[0];
		while (s[i[0]] && (!ft_strchr(set, s[i[0]]) || q[0] || q[1]))
		{
			q[0] = (q[0] + (!q[1] && s[i[0]] == '\'')) % 2;
			q[1] = (q[1] + (!q[0] && s[i[0]] == '\"')) % 2;
			i[0]++;
		}
		if (i[1] >= s_len)
			tmpstr[i[2]++] = "\0";
		else
			tmpstr[i[2]++] = ft_substr(s, i[1], i[0] - i[1]);
	}
	return (tmpstr);
}

char	**split_ignore_space_in_quote(char *s, char *set)
{
	char	**tmpstr;
	int		nwords;
	int		i[3];
	int		counts[2];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	counts[0] = 0;
	counts[1] = 0;
	if (!s)
		return (NULL);
	nwords = ft_count_tokens(s, set, counts);
	if (nwords == -1)
		return (NULL);
	tmpstr = malloc((nwords + 1) * sizeof(char *));
	if (tmpstr == NULL)
		return (ft_put_error(NULL, "Malloc failed", 1, NULL), NULL);
	tmpstr = ft_add_to_array(tmpstr, s, set, i);
	tmpstr[nwords] = NULL;
	return (tmpstr);
}
