/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:58:27 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/07 13:30:17 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Gestiona los fd del proceso hijo y ejecuta el cmd dado
@param shell estructura de uso general con las pipes
@param child estructura con el comando y el pid del hijo
*/
void	ft_child(t_shell *shell, t_child *child)
{
	if (child->cmd->redir_in->tipe == FT_RED_STD
		&& child->is_limit_end == false)
		dup2(shell->fd[PIPE_OG][WRITE], shell->fd[PIPE_NEW][READ]);
	if (child->cmd->redir_out->tipe == FT_RED_STD
		&& child->is_limit_end == false)
		dup2(shell->fd[PIPE_NEW][WRITE], shell->fd[PIPE_OG][READ]);
	close(shell->fd[PIPE_OG][WRITE]);
	close(shell->fd[PIPE_OG][READ]);
	close(shell->fd[PIPE_NEW][WRITE]);
	close(shell->fd[PIPE_NEW][READ]);
	mng_redirections(child->cmd, shell);
	cmd_executer(child->cmd, shell);
	exit(0);
}