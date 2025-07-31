/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatthes <rmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:01:43 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/02 14:18:15 by rmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

int	ft_check_quotes(char const *s1)
{
	int	count;
	int	i;
	int	dquote;
	int	squote;

	i = 0;
	count = 0;
	dquote = 0;
	squote = 0;
	while (s1 && s1[i])
	{
		squote = (squote + (!dquote && s1[i] == '\'')) % 2;
		dquote = (dquote + (!squote && s1[i] == '\"')) % 2;
		if ((s1[i] == '\"' && !squote) || (s1[i] == '\'' && !dquote))
			count++;
		i++;
	}
	if (squote || dquote)
		return (-1);
	return (count);
}

char	*ft_del_quotes(char const *s1, int squote, int dquote)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = -1;
	if (!s1 || ft_check_quotes(s1) == -1)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) - ft_check_quotes(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[++j])
	{
		squote = (squote + (!dquote && s1[j] == '\'')) % 2;
		dquote = (dquote + (!squote && s1[j] == '\"')) % 2;
		if ((s1[j] != '\"' || squote) && (s1[j] != '\'' || dquote)
			&& ++i >= 0)
			str[i] = s1[j];
	}
	str[++i] = '\0';
	return (str);
}
