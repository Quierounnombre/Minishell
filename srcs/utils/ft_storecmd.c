/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storecmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:42:02 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/15 16:44:28 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_bool	ft_storecmd(t_cmd *cmd, t_list **lst)
{
	t_list	*node;

	node = ft_lstnew(cmd);
	if (node)
	{
		*lst = node;
		return (true);
	}
	return (false);
}
