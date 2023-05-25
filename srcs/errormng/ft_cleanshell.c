/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:31:00 by vicgarci          #+#    #+#             */
/*   Updated: 2023/05/23 16:18:43 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Libera la estructura shell y todas las listas asociadas
@param shell la estructura a liberar
*/
void	ft_cleanshell(t_shell *shell)
{
	ft_lstclear(&(shell->childs->lst_head), ft_cleanchild);
	free(shell->childs);
	ft_lstclear(&(shell->cmds->lst_head), ft_cleancmd);
	free(shell->cmds);
	ft_delete_file(shell, shell->tube_file);
	free(shell->tube_file);
	free(shell);
}