/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:42:35 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/06 15:04:42 by vicgarci         ###   ########.fr       */
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
	int		error_code;

	error_code = 0;
	fd_output = 0;
	fd_output = open(cmd->redir_out->file, O_CREAT | O_TRUNC | O_WRONLY, 644);
	if (fd_output > 0)
	{
		error_code = dup2(fd_output, STDOUT_FILENO);
		if (error_code)
			ft_error(shell, error_code);
		cmd->redir_out->fd = fd_output;
		close(fd_output);
	}
	else
		ft_error(shell, fd_output);
}
