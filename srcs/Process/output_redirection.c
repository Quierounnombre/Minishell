/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:42:35 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/22 11:44:18 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Gestiona la redirección del tipo '>'
@param shell Estructura general con la información necesaria
*/
void	output_redirection(t_cmd *cmd, t_shell *shell)
{
	int		fd_output;

	fd_output = 0;
	fd_output = open(cmd->redir_out->file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd_output > 0)
	{
		if (dup2(fd_output, STDOUT_FILENO) == -1)
			ft_error(shell, errno);
		cmd->redir_out->fd = fd_output;
		close(fd_output);
	}
	else
		ft_error(shell, fd_output);
}
