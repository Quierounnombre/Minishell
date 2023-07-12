/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storechild.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:03:18 by vicgarci          #+#    #+#             */
/*   Updated: 2023/07/12 18:27:14 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	store_in_lst(t_shell *shell, t_list *node);

/*
Store a node of the list of childs
@param pid the value of the pid to be store
@param shell es la estructura general
@return true si todo va bien, false si falla
*/
t_bool	store_child(pid_t pid, t_shell *shell)
{
	t_child	*content;
	t_list	*node;

	ft_printf("CH 3\n");
	content = (t_child *)malloc(sizeof(t_child));
	if (content)
	{
		content->pid = pid;
		ft_printf("shell %p\n", shell);
		ft_printf("shell->cmds %p\n", shell->cmds);
		ft_printf("shell->cmds->current %p\n", shell->cmds->current);
		ft_printf("shell->cmds->head %p\n", shell->cmds->lst_head);
		ft_printf("shell->cmds->current->content %p\n", shell->cmds->current->content);
		content->cmd = shell->cmds->current->content;
		ft_printf("CH 4\n");
		content->is_limit_end = false;
		content->is_limit_sta = false;
		node = ft_lstnew(content);
		if (node)
		{
			store_in_lst(shell, node);
			return (true);
		}
		free(content);
	}
	return (false);
}

//Almacena el nodo en la lista
static void	store_in_lst(t_shell *shell, t_list *node)
{
	if (shell->childs->lst_head)
	{
		shell->childs->tail->next = node;
		shell->childs->size += 1;
	}
	else
	{
		shell->childs->current = node;
		shell->childs->lst_head = node;
		shell->childs->size = 1;
		shell->childs->tail = node;
	}
}
