/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:54:37 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/16 13:51:10 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void		change_pwd(t_shell *shell);
static t_bool	change_oldpwd(t_shell *shell);
static void		set_pwd_path(t_shell *shell);

void	change_dir(t_shell *shell, char *dir)
{
	struct stat	file_info;

	if (!stat(dir, &file_info))
	{
		if (change_oldpwd(shell))
			dir = DEFAULT_ROOT;
		if (chdir(dir) == -1)
		{
			perror("cd");
			g_shell->child_status = 1;
		}
		change_pwd(shell);
	}
	else
		perror("cd");
}

static t_bool	change_oldpwd(t_shell *shell)
{
	int		pos_pwd;
	char	*s;
	char	*s_old;

	pos_pwd = find_string(shell->env, "OLDPWD");
	if (pos_pwd != FT_INVALID_POS)
	{
		s_old = set_pwd_str(shell, "OLDPWD=");
		s = shell->env[pos_pwd];
		shell->env[pos_pwd] = s_old;
		free(s);
	}
	else
	{
		pos_pwd = 0;
		while (shell->env[pos_pwd])
			pos_pwd++;
		make_new_env(shell, OLDPWD_DEFAULT, pos_pwd);
		return (true);
	}
	return (false);
}

static void	change_pwd(t_shell *shell)
{
	int		pos_pwd;
	char	*s;
	char	*s_old;

	pos_pwd = find_string(shell->env, "PWD");
	if (pos_pwd != FT_INVALID_POS)
	{
		s = set_pwd_str(shell, "PWD=");
		s_old = shell->env[pos_pwd];
		shell->env[pos_pwd] = s;
		free(s_old);
	}
	else
		set_pwd_path(shell);
}

static void	set_pwd_path(t_shell *shell)
{
	int		pos_pwd;
	char	*s;
	char	*s2;

	pos_pwd = 0;
	while (shell->env[pos_pwd])
		pos_pwd++;
	s = getcwd(NULL, 0);
	if (!s)
		make_new_env(shell, PWD_DEFAULT, pos_pwd);
	else
	{
		s2 = ft_strjoin("PWD=", s);
		if (!s2)
			ft_error(shell, errno);
		free(s);
		make_new_env(shell, s2, pos_pwd);
		free(s2);
	}
}
