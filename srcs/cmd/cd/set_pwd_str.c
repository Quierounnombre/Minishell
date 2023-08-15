/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pwd_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:56:30 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/15 15:12:00 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*set_pwd_str(t_shell *shell, char *pwd)
{
	char	*s;
	char	*s2;
	int		pos_home;

	pos_home = FT_INVALID_POS;
	s = getcwd(NULL, 0);
	if (!s)
	{
		pos_home = find_string(shell->env, "HOME");
		s = shell->env[pos_home];
		s += 5;
	}
	s2 = ft_strjoin(pwd, s);
	if (pos_home == FT_INVALID_POS)
		free(s);
	if (!s2)
		ft_error(shell, errno);
	return (s2);
}
