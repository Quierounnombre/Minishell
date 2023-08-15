/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_to_default.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:55:45 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/15 14:40:56 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_reset_to_default(t_shell *shell)
{
	int		pos_home;
	char	*dir;

	pos_home = find_string(shell->env, "HOME");
	if (pos_home == FT_INVALID_POS)
	{
		pos_home = 0;
		while (shell->env[pos_home])
			pos_home++;
		make_new_env(shell, HOME_DEFAULT, pos_home);
		dir = DEFAULT_ROOT;
	}
	else
	{
		dir = shell->env[pos_home];
		dir += 5;
	}
	change_dir(shell, dir);
}
