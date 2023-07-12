/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_executer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:34:35 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/07 14:51:09 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_bool	init_pipes(t_shell *shell);
static t_bool	make_pipes(t_shell *shell);

/*
Wraper principal, es la función que gestiona todo lo que esta relacionado con
la ejecución de los comandos
@param Estructura de uso general
*/
void	process_executer(t_shell *shell)
{
	shell->childs->current = shell->childs->lst_head;
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
		}
		ft_lstclear(&(shell->childs->lst_head->next), ft_cleanchild);
	}
	ft_lstclear(&(shell->cmds->lst_head), ft_cleancmd);
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
