/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:17:24 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/13 19:13:48 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_bool	free_child(t_shell *shell);
static void		set_limits(t_shell *shell);

/*
Esta función crea una seríe n de estructuras hijo, en función del
numero de comandos
@param shell la estructura de uso general
@return Verdadero si malloc no falla, falso si lo hace.
*/
t_bool	make_childs(t_shell *shell)
{
	ft_printf("CONTENT -> %p\n", shell->cmds->current->content);
	ft_printf("CONTENT current -> %p\n", shell->cmds->current);
	shell->cmds->current = shell->cmds->lst_head;
	ft_printf("CONTENT_2 -> %p\n", shell->cmds->current->content);
	while (shell->cmds->current)
	{
		if (store_child(0, shell))
			shell->cmds->current = shell->cmds->current->next;
		else
			return (free_child(shell));
	}
	set_limits(shell);
	return (true);
}

//Libera la lista entera en caso de que pete
static t_bool	free_child(t_shell *shell)
{
	shell->cmds->current = shell->cmds->lst_head;
	shell->childs->current = shell->childs->lst_head;
	while (shell->childs->current)
	{
		shell->childs->current = shell->childs->current->next;
		free(shell->childs->lst_head);
		shell->childs->lst_head = shell->childs->current;
	}
	shell->childs->size = 0;
	return (false);
}

static void	set_limits(t_shell *shell)
{
	t_child	*child;

	child = shell->childs->lst_head->content;
	child->is_limit_sta = true;
	child = shell->childs->tail->content;
	child->is_limit_end = true;
}
