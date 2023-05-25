/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_executer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:34:35 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/25 10:39:00 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	process_executer(t_shell *shell)
{
	t_list	*lst;

	lst = shell->cmds->current;
	while (lst)
	{
		cmd_executer(shell);
		lst = lst->next;
	}
	ft_lstclear(&(shell->cmds->lst_head), ft_cleancmd);
	ft_lstclear(&(shell->childs->lst_head->next), ft_cleanchild);
}
