/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:44:18 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/31 14:04:21 by vicgarci         ###   ########.fr       */
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

	fd_input = 0;
	fd_input = open(cmd->redir_in->file, O_RDONLY);
	if (fd_input > 0)
	{
		if (dup2(fd_input, STDIN_FILENO) == -1)
			ft_error(shell, errno);
		cmd->redir_in->fd = fd_input;
		close(fd_input);
	}
	else
		ft_error(shell, fd_input);
}
