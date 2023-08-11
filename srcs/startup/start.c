/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:56:24 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/11 12:42:57 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_bool	start(t_shell **shell, char **env)
{
	if (shell)
	{
		if (init_shell_struct(shell))
		{
			if (init_signals(&(*shell)->sact))
			{
				if (clone_env(env, *shell))
				{
					(*shell)->child_status = 0;
					return (true);
				}
				ft_cleanshell(*shell);
			}
		}
	}
	return (false);
}
