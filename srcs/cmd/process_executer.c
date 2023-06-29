/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_executer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:34:35 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/29 12:01:03 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Wraper prncipal, es la función que gestiona todo lo que esta relacionado con
la ejecución de los comandos
@param Estructura de uso general
*/
void	process_executer(t_shell *shell)
{
	t_list	*lst;

	lst = shell->cmds->current;
	if (shell->cmds->size > 1)
	{
		while (lst)
		{
			lst = lst->next;
			shell->cmds->current = lst;
		}
	}
	else
		cmd_executer(shell);
	ft_lstclear(&(shell->cmds->lst_head), ft_cleancmd);
	ft_lstclear(&(shell->childs->lst_head->next), ft_cleanchild);
}
