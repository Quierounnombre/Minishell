/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_executer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:34:35 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/11 12:47:01 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_bool	init_pipes(t_shell *shell);
static t_bool	make_pipes(t_shell *shell);
static void		wait_for_all(t_shell *shell);
static int		check_built_in(t_shell *shell);

void	process_executer(t_shell *shell)
{
	shell->childs->current = shell->childs->lst_head;
	if (shell->cmds->lst_head && shell->cmds->lst_head->content)
	{
		if (make_childs(shell))
		{
			if (!check_built_in(shell))
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
				}
			}
		}
	}
	reset_shell(shell);
}

static int	check_built_in(t_shell *shell)
{
	t_child	*child;
	int		fd[2];

	if (!shell->childs->current->next)
	{
		child = shell->childs->current->content;
		if (is_built_in(child->cmd))
		{
			fix_the_stdred_struct(child, NULL);
			fd[STDIN_FILENO] = dup(STDIN_FILENO);
			fd[STDOUT_FILENO] = dup(STDOUT_FILENO);
			mng_redirections(child->cmd, shell);
			if (ft_strcmp(child->cmd->argv[0], "exit"))
				ft_printf("exit\n");
			do_build_in(child->cmd, shell);
			if (dup2(fd[STDIN_FILENO], STDIN_FILENO) == -1)
				exit(1);
			if (dup2(fd[STDOUT_FILENO], STDOUT_FILENO) == -1)
				exit(1);
			return (1);
		}
	}
	return (0);
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
