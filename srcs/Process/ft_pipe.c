/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:09:30 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/16 12:35:53 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Hay que tratar de expandir el numero de comandos que acepta de 2 a infinito

static void	ft_dupfd(t_shell *shell)
{	
	errno_t	error_code;

	error_code = dup2(shell->tube[0], STDIN_FILENO);
	if (error_code)
		ft_error(shell, error_code);
	dup2(shell->tube[1], STDOUT_FILENO);
	if (error_code)
		ft_error(shell, error_code);
}

/*
Ejecuta los 2 siguiente comandos de la lista mediante un pipe
@param shell Estructura de uso general
*/
void	ft_pipe(t_shell *shell)
{
	if (!pipe(shell->tube))
	{
		ft_dupfd(shell);
		cmd_executer(shell);
		if (shell->cmds->current->next != NULL)
			shell->cmds->current = shell->cmds->current->next;
		cmd_executer(shell);
		close(shell->tube[1]);
		close(shell->tube[0]);
	}
	else
		ft_error(shell, 0);
}
