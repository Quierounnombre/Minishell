/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storecmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:42:02 by vicgarci          #+#    #+#             */
/*   Updated: 2023/08/11 12:42:23 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_bool	ft_storecmd(t_cmd *cmd, t_lstmng *mng)
{
	t_list	*node;

	node = ft_lstnew(cmd);
	if (node)
	{
		if (!(mng->lst_head))
		{
			mng->lst_head = node;
			mng->current = node;
			mng->tail = node;
			mng->tail->next = NULL;
			mng->size = 1;
			return (true);
		}
		mng->tail->next = node;
		mng->tail = mng->tail->next;
		mng->tail->next = NULL;
		mng->size++;
		return (true);
	}
	return (false);
}
