/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:06:21 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/14 11:18:46 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	wait_for_all(t_shell *shell)
{
	t_child	*child;
	int		pos;

	shell->childs->current = shell->childs->tail;
	pos = shell->childs->size;
	while (pos)
	{
		child = shell->childs->current->content;
		waitpid(child->pid, &(shell->child_status), 0);
		pos--;
		shell->childs->current = ft_lstnnode(shell->childs->lst_head, pos);
	}
}
