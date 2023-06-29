/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storechild.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:03:18 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/29 11:44:57 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Store a node of the list of childs
@param pid the value of the pid to be store
@param lst es la dirección de memoria donde se va a almacenar la lista
@param shell es la estructura general
@return true si todo va bien, false si falla
*/
t_bool	store_child(pid_t pid, t_list **lst, t_shell *shell)
{
	t_child	*content;
	t_list	*node;

	content = (t_child *)malloc(sizeof(t_child));
	if (content)
	{
		content->pid = pid;
		content->cmd = shell->cmds->current->content;
		node = ft_lstnew(content);
		if (node)
		{
			*lst = node;
			return (true);
		}
		free(content);
	}
	return (false);
}
