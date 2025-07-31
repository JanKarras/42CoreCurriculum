/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:38:08 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 19:48:30 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

int	ft_pwd(t_data *data)
{
	char	*pwd;

	pwd = ft_getenv("PWD", data->envp);
	if (!pwd)
		return (ft_put_error(NULL, "PWD error", 1, NULL), 1);
	return (ft_putendl_fd(pwd, 1), free(pwd), 0);
}
