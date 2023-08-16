/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:58:27 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/16 12:30:49 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	close_pipes(t_shell *shell);
static void	std_red(t_child *child, t_shell *shell);
static void	cmd_not_found(t_child *child);

void	ft_child(t_shell *shell, t_child *child)
{
	signal(SIGQUIT, SIG_DFL);
	std_red(child, shell);
	close_pipes(shell);
	mng_redirections(child->cmd, shell);
	if (child->cmd->filepath && ft_strchr(child->cmd->filepath, '/'))
		cmd_executer(child->cmd, shell);
	else if (child->cmd->argv[0])
		cmd_not_found(child);
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

static void	close_pipes(t_shell *shell)
{
	close(shell->fd[PIPE_OG][WRITE]);
	close(shell->fd[PIPE_OG][READ]);
	close(shell->fd[PIPE_NEW][WRITE]);
	close(shell->fd[PIPE_NEW][READ]);
}

static void	cmd_not_found(t_child *child)
{
	if (!is_built_in(child->cmd))
	{
		g_shell->child_status = 127;
		ft_printf("%s: %s: %s\n",
			"Minishell",
			*(child->cmd->argv),
			CMD_NOT_FOUND);
		exit(127);
	}
}
