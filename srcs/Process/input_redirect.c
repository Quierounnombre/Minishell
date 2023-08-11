/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:44:18 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/11 12:40:23 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
