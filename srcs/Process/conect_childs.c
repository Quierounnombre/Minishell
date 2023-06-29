/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conect_childs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:17:44 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/29 16:00:23 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	make_pipe(t_child *child);

/*
Conecta las diferentes estructuras de hijos mediante fd
@param shell estructura de uso generaal
@return En caso de que falle pipe devuele false
*/
t_bool	conect_childs(t_shell *shell)
{
	t_child	*child;

	shell->childs->current = shell->childs->lst_head;
	if (shell->childs->size > 1)
	{
		while (shell->childs->current->next)
		{
			child = shell->childs->current->content;
			if (!pipe(child->fd))
				make_pipe(child);
			else
				return (false);
			shell->childs->current = shell->childs->current->next;
		}
	}
	if (shell->childs->size == 1)
		return (true);
	return (false);
}

static void	make_pipe(t_child *child)
{
	if (child->cmd->redir_in->tipe == FT_RED_STD)
	{
		dup2(child->fd[0], STDIN_FILENO);
		close(child->fd[0]);
	}
	if (child->cmd->redir_out->tipe == FT_RED_OUT)
	{
		dup2(child->fd[1], STDOUT_FILENO);
		close(child->fd[1]);
	}
}
