/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:49:52 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/22 16:08:46 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Seleciona el primer comando, hace el fork, gestiona los errores y lo ejecuta.
@param shell es la estructura general de la consola, necesaria para el fork
*/
void	cmd_executer(t_cmd *cmd, t_shell *shell)
{
	if (is_built_in(cmd))
		do_build_in(cmd, shell);
	else
	{
		/*int i = 0;
		while (cmd->argv[i])
		{
			fprintf(stderr, "%s\n", cmd->argv[i]);
			i++;
		}*/
		if (cmd->filepath)
			execve(cmd->filepath, cmd->argv, shell->env);
		else
			ft_error(shell, ENOENT);
	}
	ft_error(shell, 0);
}
