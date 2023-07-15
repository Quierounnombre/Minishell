/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:44:18 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/15 17:48:57 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Gestiona la apertura de la redirección del tipo '<'.
@param shell la estructura general con toda la información relacionada
*/
void	input_redirect(t_cmd *cmd, t_shell *shell)
{
	int		fd_input;
	int		error_code;

	error_code = 0;
	fd_input = 0;
	fd_input = open(cmd->redir_in->file, O_RDONLY);
	if (fd_input > 0)
	{
		error_code = dup2(fd_input, STDIN_FILENO);
		if (error_code == -1)//el dup2 en caso de error devuelve un -1
			ft_error(shell, error_code);
		cmd->redir_in->fd = fd_input;
		close(fd_input);
	}
	else
		ft_error(shell, fd_input);
}
