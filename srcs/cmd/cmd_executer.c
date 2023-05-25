/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:49:52 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/25 12:02:05 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_child(t_shell *shell)
{
	t_cmd	*cmd;
	errno_t	error_code;

	cmd = shell->cmds->current->content;
	error_code = 0;
	mng_redirections(shell);
	if (is_built_in(shell))
		do_build_in(shell);
	else
		error_code = execve(cmd->filepath, cmd->argv, cmd->env);
	ft_error(shell, error_code);
}

//BUILT-IN que pasa con el path????? no deberiamos ejecutar primero el std si
//podemos y en caso contrario el built-in???????????????? VICENTE LAS COSAS
//CLARAAAAAAAAAAAS

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
