/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:54:37 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/15 15:04:25 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void		change_pwd(t_shell *shell);
static t_bool	change_oldpwd(t_shell *shell);

void	change_dir(t_shell *shell, char *dir)
{
	struct stat	file_info;

	if (!stat(dir, &file_info))
	{
		if (change_oldpwd(shell))
			dir = DEFAULT_ROOT;
		if (chdir(dir) == -1)
			perror("cd");
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
	{
		pos_pwd = 0;
		while (shell->env[pos_pwd])
			pos_pwd++;
		make_new_env(shell, PWD_DEFAULT, pos_pwd);
	}
}
