/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storechild.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:03:18 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/11 16:03:36 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Store a node in this context this will store a pid
@param pid the value of the pid to be store
@param lst es la dirección de memoria donde se va a almacenar la lista
@return true si todo va bien, false si falla
*/
t_bool	store_node(pid_t pid, t_list **lst)
{
	pid_t	*content;
	t_list	*node;

	content = (pid_t *)malloc(sizeof(pid_t));
	if (content)
	{
		*content = pid;
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
