/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:26:26 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/14 18:06:33 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_bool	add_string_to_env(char *s, char **env, int pos);
static t_bool	make_env(t_shell *shell);
static t_bool	add_pwd(char *str, char **env, int pos);

t_bool	start_env(char **env, t_shell *shell)
{
	if (*env)
	{
		if (clone_env_init(env, shell))
		{
			shell->child_status = 0;
			return (true);
		}
	}
	else
	{
		if (make_env(shell))
			return (true);
	}
	return (false);
}

static t_bool	make_env(t_shell *shell)
{
	char	**env;

	env = (char **)malloc(sizeof(char *) * 6);
	if (env)
	{
		shell->env = env;
		env[5] = NULL;
		if (!add_string_to_env("HOME=/Users/", env, 0))
			return (false);
		if (!add_string_to_env("SHLVL=1", env, 1))
			return (false);
		if (!add_string_to_env("_=/usr/bin/env", env, 2))
			return (false);
		if (!add_pwd("PWD=", env, 3))
			return (false);
		if (!add_pwd("OLDPWD=", env, 4))
			return (false);
	}
	return (true);
}

static t_bool	add_string_to_env(char *s, char **env, int pos)
{
	char	*str;

	str = ft_strdup(s);
	if (str)
	{
		env[pos] = str;
		return (true);
	}
	return (false);
}

static t_bool	add_pwd(char *str, char **env, int pos)
{
	char	*pwd;
	char	*s;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (false);
	s = ft_strjoin(str, pwd);
	if (!s)
		return (false);
	env[pos] = s;
	free(pwd);
	return (true);
}
