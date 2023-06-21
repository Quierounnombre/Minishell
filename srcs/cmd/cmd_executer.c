/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:49:52 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/31 16:15:30 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_child(t_shell *shell)
{
	t_cmd	*cmd;

	cmd = shell->cmds->current->content;
	mng_redirections(shell);
	if (is_built_in(shell))
		do_build_in(shell);
	else
	{
		if (cmd->filepath)
			execve(cmd->filepath, cmd->argv, cmd->env);
		else
			ft_error(shell, ENOENT);
	}
	ft_error(shell, 0);
}

/*
Seleciona el primer comando, hace el fork, gestiona los errores y lo ejecuta.
@param shell es la estructura general de la consola, necesaria para el fork
*/
void	cmd_executer(t_shell *shell)
{
	t_cmd	*cmd;
	int		child_status;

	child_status = 0;
	cmd = shell->cmds->current->content;
	if (do_fork(shell))
	{
		if (shell->self_pid == 0)
			ft_child(shell);
		else
		{
			waitpid(*(pid_t *)(shell->childs->current->content), &child_status,
				0);
			if (cmd->redir_in->tipe == FT_RED_HEREDOC)
				ft_delete_file(shell, cmd->redir_in->file);
		}
	}
	else
		ft_error(shell, errno);
}
