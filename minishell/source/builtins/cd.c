/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:28:16 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 20:15:09 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_check_home_pwd_oldpwd(t_data *data)
{
	char	*pwd;
	char	*oldpwd;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	pwd = ft_getenv("PWD", data->envp);
	oldpwd = ft_getenv("OLDPWD", data->envp);
	if (!pwd)
		data->envp = ft_setenv("PWD", cwd, data->envp);
	if (!oldpwd)
		data->envp = ft_setenv("OLDPWD", cwd, data->envp);
	ft_free_all(pwd, oldpwd, cwd, NULL);
}

int	ft_cd(t_data *data, char **args)
{
	char	*new_pwd;
	char	*old_pwd;

	data->status_code = 0;
	new_pwd = ft_strdup("");
	ft_check_home_pwd_oldpwd(data);
	if (a_len(args) != 2)
		return (ft_put_error(NULL, "cd: too many arguments", 1, data), 1);
	old_pwd = ft_getenv("PWD", data->envp);
	if (!ft_strcmp(args[1], "~"))
		chdir(ft_getenv("HOME", data->envp));
	else if (!ft_strcmp(args[1], "/"))
		chdir("/");
	else if (!ft_strcmp(args[1], "-"))
		chdir(ft_getenv("OLDPWD", data->envp));
	else if (!access(args[1], F_OK))
		chdir(args[1]);
	else if (access(args[1], F_OK))
		return (ft_put_error(NULL, "No such file or directory", 1, NULL), 1);
	ft_setenv("OLDPWD", old_pwd, data->envp);
	new_pwd = getcwd(NULL, 0);
	ft_setenv("PWD", new_pwd, data->envp);
	ft_free_all(new_pwd, old_pwd, NULL, NULL);
	return (data->status_code);
}
