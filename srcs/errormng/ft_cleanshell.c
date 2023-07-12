/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:31:00 by vicgarci          #+#    #+#             */
/*   Updated: 2023/06/29 12:00:22 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	clean_env(t_shell *shell)
{
	int		i;

	i = 0;
	if (shell->env)
	{
		while (i)
		{
			free(shell->env[i]);
			i++;
		}
		free(shell->env);
	}
}

/*
Libera la estructura shell y todas las listas asociadas
@param shell la estructura a liberar
*/
void	ft_cleanshell(t_shell *shell)
{
	if (shell->childs->lst_head)
		ft_lstclear(&(shell->childs->lst_head), ft_cleanchild);
	free(shell->childs);
	if (shell->cmds->lst_head)
		ft_lstclear(&(shell->cmds->lst_head), ft_cleancmd);
	free(shell->cmds);
	clean_env(shell);
	free(shell);
}
