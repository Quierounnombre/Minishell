/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:58:27 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/22 19:02:20 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	std_red(t_child *child, t_shell *shell);

/*
Gestiona los fd del proceso hijo y ejecuta el cmd dado
@param shell estructura de uso general con las pipes
@param child estructura con el comando y el pid del hijo
*/
void	ft_child(t_shell *shell, t_child *child)
{
	std_red(child, shell);
	close(shell->fd[PIPE_OG][WRITE]);
	close(shell->fd[PIPE_OG][READ]);
	close(shell->fd[PIPE_NEW][WRITE]);
	close(shell->fd[PIPE_NEW][READ]);
	mng_redirections(child->cmd, shell);
	cmd_executer(child->cmd, shell);
	exit(0);
}

static void	std_red(t_child *child, t_shell *shell)
{
	fix_the_stdred_struct(child, NULL);
	if (!(child->cmd->redir_in) && shell->childs->size > 1)
	{
		if (child->is_limit_sta && !(child->is_limit_end))
			dup2(shell->fd[PIPE_NEW][WRITE], STDOUT_FILENO);
		if (!(child->is_limit_sta) && !(child->is_limit_end))
		{
			dup2(shell->fd[PIPE_OG][READ], STDIN_FILENO);
			dup2(shell->fd[PIPE_NEW][WRITE], STDOUT_FILENO);
		}
		if (!(child->is_limit_sta) && child->is_limit_end)
			dup2(shell->fd[PIPE_OG][READ], STDIN_FILENO);
	}
}
