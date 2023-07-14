/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:28:33 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/14 15:19:08 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Gestiona los errores y en caso de ser necesario libera la memoria
@param shell la estructura general en caso de ser necesario liberarla
@param error_code el codigo de error
*/
void	ft_error(t_shell *shell, errno_t error_code)
{
	t_cmd	*cmd;
	char	*s;

	if (shell && shell->cmds && shell->cmds->current
		&& shell->cmds->current->content)
		cmd = shell->cmds->current->content;
	if (error_code)
	{
		s = strerror(error_code);
		perror(s);
	}
	if (shell->self_pid)
		ft_cleanshell(shell);
	else
	{
		if (cmd->redir_in->fd < 0)
			close(cmd->redir_in->fd);
		if (cmd->redir_out->fd < 0)
			close(cmd->redir_out->fd);
	}
	exit(error_code);
}
