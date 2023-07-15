/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:25:48 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/15 17:56:35 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Gestiona la redirección del tipo '>>'
@param shell estructura general con la información necesaria
*/
void	output_append(t_cmd *cmd, t_shell *shell)
{
	int		fd_output;
	int		error_code;

	error_code = 0;
	fd_output = 0;
	fd_output = open(cmd->redir_out->file, O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (fd_output > 0)
	{
		error_code = dup2(fd_output, STDOUT_FILENO);
		if (error_code == -1)
			ft_error(shell, error_code);
		cmd->redir_out->fd = fd_output;
		close(fd_output);
	}
	else
		ft_error(shell, fd_output);
}
