/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:49:52 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/11 12:39:57 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_executer(t_cmd *cmd, t_shell *shell)
{
	if (is_built_in(cmd))
	{
		do_build_in(cmd, shell);
		exit (0);
	}
	else
	{
		if (cmd->filepath)
			execve(cmd->filepath, cmd->argv, shell->env);
		else if (cmd->argv[0])
			ft_error(shell, ENOENT);
	}
	ft_error(shell, 0);
}
