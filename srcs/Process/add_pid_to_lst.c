/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pid_to_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:17:30 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/10 15:30:11 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*Add the child pid to the lstmng, and update it apropiatly,
 where is store for future use.*/
t_bool	add_pid_to_lst(t_lstmng *mng, pid_t pid)
{
	t_list	*lst;
	pid_t	*content;

	content = (pid_t *)malloc(sizeof(pid_t));
	if (content)
	{
		*content = pid;
		lst = ft_lstnew(content);
		if (lst)
		{
			mng->tail->next = lst;
			mng->tail = lst;
			mng->size++;
			return (true);
		}
		free(content);
	}
	return (false);
}
