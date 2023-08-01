/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:52:38 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/01 15:13:46 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	change_dir(t_shell *shell, const char *dir);
static char	*set_pwd_str(t_shell *shell, char *pwd);
static void	ft_reset_to_default(t_shell *shell);

/*
Cambia de direcctorio al objetivo
@param dir el directorio a donde vamos a cambiar
@param shell porta el env y en caso de error para cerrar la shell
*/
void	ft_cd(const char *dir, t_shell *shell)
{
	if (dir)
		change_dir(shell, dir);
	else
		ft_reset_to_default(shell);
}

static char	*set_pwd_str(t_shell *shell, char *pwd)
{
	char	*s;

	s = getcwd(NULL, 0);
	if (!s)
		ft_error(shell, errno);
	s = ft_strjoin(pwd, s);
	if (!s)
		ft_error(shell, errno);
	return (s);
}

static void	change_dir(t_shell *shell, const char *dir)
{
	struct stat	file_info;
	char		*s_old;
	char		*s;
	int			pos_pwd;

	if (!stat(dir, &file_info))
	{
		s_old = set_pwd_str(shell, "OLDPWD=");
		pos_pwd = find_string(shell->env, "OLDPWD");
		s = shell->env[pos_pwd];
		shell->env[pos_pwd] = s_old;
		free(s);
		if (chdir(dir) == -1)
			perror("cd");
		s = set_pwd_str(shell, "PWD=");
		pos_pwd = find_string(shell->env, "PWD");
		s_old = shell->env[pos_pwd];
		shell->env[pos_pwd] = s;
		free(s_old);
	}
	else
		perror("cd");
}

static void	ft_reset_to_default(t_shell *shell)
{
	int		pos_home;
	char	*dir;

	pos_home = find_string(shell->env, "HOME");
	dir = shell->env[pos_home];
	dir += 5;
	change_dir(shell, dir);
}
