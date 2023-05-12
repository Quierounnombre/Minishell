/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:09:30 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/12 17:48:14 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Hay que tratar de expandir el numero de comandos que acepta de 2 a infinito

/*
Ejecuta los 2 siguiente comandos de la lista y los encadena
*/
void	ft_pipe(t_shell *shell)
{
	int		fd[2];

	if (!pipe(fd))
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		cmd_manager(shell->cmds->current->content, shell);
		if (shell->cmds->current->next != NULL)
			shell->cmds->current = shell->cmds->current->next;
		cmd_manager(shell->cmds->current->content, shell);
		close(fd[1]);
		close(fd[0]);
	}
}
