/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_executer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:34:35 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/21 20:17:41 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_bool	init_pipes(t_shell *shell);
static t_bool	make_pipes(t_shell *shell);
static void		wait_for_all(t_shell *shell);

/*
Wraper principal, es la función que gestiona todo lo que esta relacionado con
la ejecución de los comandos
@param Estructura de uso general
*/
/*void	process_executer(t_shell *shell)
{
	shell->childs->current = shell->childs->lst_head;
	if (shell->cmds->lst_head && shell->cmds->lst_head->content)
	{
		if (make_childs(shell))
		{
			if (init_pipes(shell))
			{
				while (shell->childs->current)
				{
					fork_child(shell);
					shell->childs->current = shell->childs->current->next;
					if (!make_pipes(shell))
						break ;
				}
				wait_for_all(shell);
				heredoc_unlink(shell);
			}
			if (shell->childs->lst_head)
				ft_lstclear(&(shell->childs->lst_head->next), ft_cleanchild);
		}
	}
}*/

void	check_exit(t_shell *shell)
{
	t_child	*child;

	if (!(shell->childs->current->next))
	{
		child = shell->childs->current->content;
		if (!(ft_strcmp(child->cmd->argv[0], "exit")))
			ft_exit(shell);
	}
}

void	process_executer(t_shell *shell)
{
	shell->childs->current = shell->childs->lst_head;
	if (shell->cmds->lst_head && shell->cmds->lst_head->content)
	{
		if (make_childs(shell))
		{
			if (init_pipes(shell))
			{
					check_exit(shell);
				while (shell->childs->current)
				{
					fork_child(shell);
					shell->childs->current = shell->childs->current->next;
					if (!make_pipes(shell))
						break ;
				}
				wait_for_all(shell);
				heredoc_unlink(shell);
			}
			if (shell->childs->lst_head)
				ft_lstclear(&(shell->childs->lst_head->next), ft_cleanchild);
		}
	}
}

static void	wait_for_all(t_shell *shell)
{
	t_child	*child;

	close(shell->fd[PIPE_OG][READ]);
	close(shell->fd[PIPE_OG][WRITE]);
	close(shell->fd[PIPE_NEW][READ]);
	close(shell->fd[PIPE_NEW][WRITE]);
	shell->childs->current = shell->childs->lst_head;
	while (shell->childs->current)
	{
		child = shell->childs->current->content;
		waitpid(child->pid, &(shell->child_status), 0);
		shell->childs->current = shell->childs->current->next;
	}
}

static t_bool	init_pipes(t_shell *shell)
{
	if (!pipe(shell->fd[PIPE_OG]))
		if (!pipe(shell->fd[PIPE_NEW]))
			return (true);
	return (false);
}

static t_bool	make_pipes(t_shell *shell)
{
	close(shell->fd[PIPE_OG][READ]);
	close(shell->fd[PIPE_OG][WRITE]);
	shell->fd[PIPE_OG][READ] = shell->fd[PIPE_NEW][READ];
	shell->fd[PIPE_OG][WRITE] = shell->fd[PIPE_NEW][WRITE];
	if (!pipe(shell->fd[PIPE_NEW]))
		return (true);
	return (false);
}
