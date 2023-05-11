/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:49:52 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/11 16:51:41 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Recibe un cmd, le hace el fork, gestiona los errores y lo ejecuta.
@param cmd es el comando que se quiere ejecutar.
@param shell es la estructura general de la consola, necesaria para el fork
*/
void	cmd_manager(t_cmd *cmd, t_shell *shell)
{
	if (do_fork(shell))
	{
		if (shell->self_pid == 0)
			execve(cmd->filepath, cmd->argv, cmd->env);
	}
	//ERROR?
}
