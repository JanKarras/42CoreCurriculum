/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatthes <rmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:17:45 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/02 14:25:02 by rmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

int	ft_char_count(char *s, char c)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count);
}

int	ft_index_strchrs(const char *s, char *set)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (ft_strchr(set, s[i]))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_index_strchr(const char *s, int c)
{
	unsigned char	c_unsigned;
	int				i;

	i = 0;
	if (!s)
		return (-1);
	c_unsigned = (unsigned char)c;
	while (s[i++])
		if (s[i] == c_unsigned)
			return (i);
	if (c_unsigned == '\0')
		return (i);
	return (-1);
}

char	*ft_join_3_strings(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*ret;

	ret = NULL;
	tmp = ft_strjoin(s1, s2);
	if (tmp)
	{
		ret = ft_strjoin(tmp, s3);
		ft_free_all(tmp, NULL, NULL, NULL);
	}
	return (ret);
}

int	ft_printf_fd(int fd, char *format, ...)
{
	char	*str;
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			write(fd, format, 1);
		else
		{
			if (*++format == 's')
			{
				str = va_arg(ap, char *);
				if (!str)
					str = "(null)";
				while (*str)
					write(fd, str++, 1);
			}
		}
		format++;
	}
	va_end(ap);
	return (1);
}
