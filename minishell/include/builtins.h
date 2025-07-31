/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:23:49 by rmatthes          #+#    #+#             */
/*   Updated: 2024/09/08 19:55:23 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

typedef struct s_data	t_data;
typedef struct s_cmd	t_cmd;

// builtin cd.c
// void	ft_chdir(char ***av, char *home, char *oldpwd, t_data *data);
void	ft_check_home_pwd_oldpwd(t_data *data);
int		ft_cd(t_data *data, char **cmd_args);

// builtin echo.c
int		ft_echo(t_cmd *cmd);

// builtin env.c
int		ft_get_var_index(char *var, char **envp);
char	*ft_getenv(char *var, char **envp);
char	**ft_setenv(char *var, char *value, char **envp);
void	ft_handle_env_vars(char *str, int *i, int fd[2], t_data *data);

// builtin exit.c
void	ft_free_exit(t_data *data, int exit_code, char *msg);
void	ft_exit(t_list *cmd, int *is_exit, t_data *data);

// builtin export.c
// int		ft_var_in_env(char *argv, char **envp, int ij[2]);
// int		ft_is_valid_ident(char *str);
int		ft_export(t_data *data, char **args);

// builtin pwd.c
int		ft_pwd(t_data *data);

// builtin unset.c
int		ft_unset(t_data *data, char **args);

// builtin check_builtin.c
int		is_builtin(t_cmd *n);
int		ft_cd_export_unset_exit(t_data *data, t_list *cmd, int *is_exit, int n);
void	ft_pwd_echo_env(t_data *data, t_cmd *n, int l, t_list *cmd);

#endif
