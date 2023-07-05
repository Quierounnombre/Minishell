/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:49:52 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/05 12:47:44 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Seleciona el primer comando, hace el fork, gestiona los errores y lo ejecuta.
@param shell es la estructura general de la consola, necesaria para el fork
*/
void	cmd_executer(t_cmd *cmd)
{
	mng_redirections(shell);
	if (is_built_in(shell))
		do_build_in(shell);
	else
	{
		if (cmd->filepath)
			execve(cmd->filepath, cmd->argv, shell->env);
		else
			ft_error(shell, ENOENT);
	}
	ft_error(shell, 0);
}
