/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:49:52 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/15 16:57:48 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Seleciona el primer comando, hace el fork, gestiona los errores y lo ejecuta.
@param shell es la estructura general de la consola, necesaria para el fork
*/
void	cmd_manager(t_shell *shell)
{
	t_cmd	*cmd;
	errno_t	error_code;
	int		child_status;

	child_status = 0;
	error_code = 0;
	cmd = shell->cmds->current->content;
	if (do_fork(shell))
	{
		if (shell->self_pid == 0)
		{
			error_code = execve(cmd->filepath, cmd->argv, shell->env);
			ft_error(shell, error_code);
		}
		else
			waitpid(*(pid_t *)(shell->childs->current->content), &child_status,
				0);
	}
	else
		ft_error(shell, error_code);
}
