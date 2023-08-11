/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:25:48 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/11 12:40:37 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	output_append(t_cmd *cmd, t_shell *shell)
{
	int		fd_output;

	fd_output = 0;
	fd_output = open(cmd->redir_out->file, O_CREAT | O_APPEND | O_WRONLY, 0644);
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
