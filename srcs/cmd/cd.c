/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:52:38 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/26 14:59:44 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Cambia de direcctorio al objetivo
@param dir el directorio a donde vamos a cambiar
@param shell porta el env y en caso de error para cerrar la shell
*/
void	ft_cd(const char *dir, t_shell *shell)
{
	int		pos_pwd;
	char	*s;
	char	*s_old;

	pos_pwd = find_string(shell->env, "PWD=");
	s = NULL;
	s = ft_strjoin("PWD=", dir);
	if (s)
	{
		if (chdir(dir))
			ft_error(shell, errno);
		s_old = shell->env[pos_pwd];
		shell->env[pos_pwd] = s;
		pos_pwd = find_string(shell->env, "OLDPWD=");
		free(shell->env[pos_pwd]);
		shell->env[pos_pwd] = s_old;
	}
}
