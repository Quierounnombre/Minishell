/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:58:27 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/14 18:05:01 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	std_red(t_child *child, t_shell *shell);
static void	fix_the_stdred_struct(t_child	*child, t_red *red);

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
	if (child->cmd->redir_in->tipe == FT_RED_STD && shell->childs->size > 1)
	{
		if (!(child->is_limit_sta))
			dup2(shell->fd[PIPE_OG][WRITE], shell->fd[PIPE_NEW][READ]);
		if (!(child->is_limit_end))
			dup2(shell->fd[PIPE_NEW][WRITE], shell->fd[PIPE_OG][READ]);
		if (child->is_limit_sta)
			dup2(STDIN_FILENO, shell->fd[PIPE_OG][READ]);
		if (child->is_limit_end)
			dup2(shell->fd[PIPE_OG][WRITE], STDOUT_FILENO);
	}
}

static void	fix_the_stdred_struct(t_child	*child, t_red *red)
{
	red = child->cmd->redir_in;
	while (red->next && red->tipe != FT_RED_STD)
	{
		child->cmd->redir_in->fd = open(child->cmd->redir_in->file,
				O_CREAT | O_TRUNC);
		close(child->cmd->redir_in->fd);
		child->cmd->redir_in = child->cmd->redir_in->next;
		free(red);
		red = child->cmd->redir_in;
	}
	red = child->cmd->redir_out;
	while (red->next && red->tipe != FT_RED_STD)
	{
		child->cmd->redir_in->fd = open(child->cmd->redir_in->file,
				O_CREAT | O_TRUNC);
		close(child->cmd->redir_in->fd);
		child->cmd->redir_in = child->cmd->redir_in->next;
		free(red);
		red = child->cmd->redir_in;
	}
}
